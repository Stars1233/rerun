use re_chunk::LatestAtQuery;
use re_log_types::{EntityPath, Instance};
use re_types::{
    self,
    archetypes::{self, GraphEdges},
    components, datatypes,
};
use re_view::{DataResultQuery as _, RangeResultsExt as _};
use re_viewer_context::{
    self, IdentifiedViewSystem, ViewContext, ViewContextCollection, ViewQuery,
    ViewSystemExecutionError, ViewSystemIdentifier, VisualizerQueryInfo, VisualizerSystem,
};

use crate::graph::NodeId;

#[derive(Default)]
pub struct EdgesVisualizer {
    pub data: ahash::HashMap<EntityPath, EdgeData>,
}

pub struct EdgeInstance {
    // We will need this in the future, when we want to select individual edges.
    pub instance: Instance,
    pub source: components::GraphNode,
    pub target: components::GraphNode,
    pub source_index: NodeId,
    pub target_index: NodeId,
}

pub struct EdgeData {
    pub graph_type: components::GraphType,
    pub edges: Vec<EdgeInstance>,
}

impl IdentifiedViewSystem for EdgesVisualizer {
    fn identifier() -> ViewSystemIdentifier {
        "GraphEdges".into()
    }
}

impl VisualizerSystem for EdgesVisualizer {
    fn visualizer_query_info(&self) -> VisualizerQueryInfo {
        VisualizerQueryInfo::from_archetype::<archetypes::GraphEdges>()
    }

    /// Populates the visualizer with data from the store.
    fn execute(
        &mut self,
        ctx: &ViewContext<'_>,
        query: &ViewQuery<'_>,
        _context_systems: &ViewContextCollection,
    ) -> Result<Vec<re_renderer::QueueableDrawData>, ViewSystemExecutionError> {
        let timeline_query = LatestAtQuery::new(query.timeline, query.latest_at);

        // TODO(cmc): could we (improve and then) use reflection for this?
        re_types::static_assert_struct_has_fields!(
            datatypes::Utf8Pair,
            first: datatypes::Utf8,
            second: datatypes::Utf8,
        );
        const SOURCE: &str = "first";
        const TARGET: &str = "second";

        for data_result in query.iter_visible_data_results(Self::identifier()) {
            let results = data_result
                .latest_at_with_blueprint_resolved_data::<archetypes::GraphEdges>(
                    ctx,
                    &timeline_query,
                );

            let all_edges = results.iter_as(query.timeline, GraphEdges::descriptor_edges());
            let graph_type = results
                .get_mono::<components::GraphType>(&GraphEdges::descriptor_graph_type())
                .unwrap_or_default();

            let sources = all_edges
                .slice_from_struct_field::<String>(SOURCE)
                .map(|(_index, source)| source);
            let targets = all_edges
                .slice_from_struct_field::<String>(TARGET)
                .map(|(_index, target)| target);

            for (sources, targets) in itertools::izip!(sources, targets) {
                let edges = itertools::izip!(sources, targets)
                    .enumerate()
                    .map(|(i, (source, target))| {
                        let source = components::GraphNode(source.into());
                        let target = components::GraphNode(target.into());

                        let entity_path = &data_result.entity_path;
                        let source_index = NodeId::from_entity_node(entity_path, &source);
                        let target_index = NodeId::from_entity_node(entity_path, &target);

                        EdgeInstance {
                            instance: Instance::from(i as u64),
                            source,
                            target,
                            source_index,
                            target_index,
                        }
                    })
                    .collect();

                self.data.insert(
                    data_result.entity_path.clone(),
                    EdgeData { edges, graph_type },
                );
            }
        }

        // We're not using `re_renderer` here, so return an empty vector.
        // If you want to draw additional primitives here, you can emit re_renderer draw data here directly.
        Ok(Vec::new())
    }

    fn as_any(&self) -> &dyn std::any::Any {
        self
    }

    fn fallback_provider(&self) -> &dyn re_viewer_context::ComponentFallbackProvider {
        self
    }
}

re_viewer_context::impl_component_fallback_provider!(EdgesVisualizer => []);
