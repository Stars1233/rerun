//! Various strongly typed sets of entities to express intent and avoid mistakes.

use nohash_hasher::{IntMap, IntSet};
use re_log_types::EntityPath;

use crate::ViewSystemIdentifier;

/// List of entities that are *applicable* to a given visualizer.
///
/// An entity is applicable if it at any point in time on any timeline has all required components.
#[derive(Default, Clone, Debug)]
pub struct ApplicableEntities(pub IntSet<EntityPath>);

impl std::ops::Deref for ApplicableEntities {
    type Target = IntSet<EntityPath>;

    #[inline]
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

/// List of entities that match the indicator components of a visualizer.
///
/// In order to be a match the entity must have at some point in time on any timeline had any of
/// the indicator components specified by the respective visualizer system.
#[derive(Default, Clone)]
pub struct IndicatedEntities(pub IntSet<EntityPath>);

impl std::ops::Deref for IndicatedEntities {
    type Target = IntSet<EntityPath>;

    #[inline]
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

/// List of entities that can be visualized at some point in time on any timeline
/// by a concrete visualizer in the context of a specific instantiated view.
///
/// It gets invalidated whenever any properties of the respective view instance
/// change, e.g. its origin.
/// TODO(andreas): Unclear if any of the view's configuring blueprint entities are included in this!
///
/// This is a subset of [`ApplicableEntities`] and differs on a
/// per view instance base.
#[derive(Default, Clone, Debug)]
pub struct VisualizableEntities(pub IntSet<EntityPath>);

impl std::ops::Deref for VisualizableEntities {
    type Target = IntSet<EntityPath>;

    #[inline]
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

#[derive(Default, Debug)]
pub struct PerVisualizer<T: Default>(pub IntMap<ViewSystemIdentifier, T>);

impl<T: Default> std::ops::Deref for PerVisualizer<T> {
    type Target = IntMap<ViewSystemIdentifier, T>;

    #[inline]
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}
