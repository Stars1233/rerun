// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/rust/api.rs
// Based on "crates/store/re_types/definitions/rerun/archetypes/series_point.fbs".

#![allow(unused_imports)]
#![allow(unused_parens)]
#![allow(clippy::clone_on_copy)]
#![allow(clippy::cloned_instead_of_copied)]
#![allow(clippy::map_flatten)]
#![allow(clippy::needless_question_mark)]
#![allow(clippy::new_without_default)]
#![allow(clippy::redundant_closure)]
#![allow(clippy::too_many_arguments)]
#![allow(clippy::too_many_lines)]

use ::re_types_core::external::arrow;
use ::re_types_core::SerializationResult;
use ::re_types_core::{ComponentBatch, ComponentBatchCowWithDescriptor};
use ::re_types_core::{ComponentDescriptor, ComponentName};
use ::re_types_core::{DeserializationError, DeserializationResult};

/// **Archetype**: Define the style properties for a point series in a chart.
///
/// This archetype only provides styling information and should be logged as static
/// when possible. The underlying data needs to be logged to the same entity-path using
/// [`archetypes::Scalar`][crate::archetypes::Scalar].
///
/// ## Example
///
/// ### Point series
/// ```ignore
/// fn main() -> Result<(), Box<dyn std::error::Error>> {
///     let rec = rerun::RecordingStreamBuilder::new("rerun_example_series_point_style").spawn()?;
///
///     // Set up plot styling:
///     // They are logged static as they don't change over time and apply to all timelines.
///     // Log two point series under a shared root so that they show in the same plot by default.
///     rec.log_static(
///         "trig/sin",
///         &rerun::SeriesPoint::new()
///             .with_color([255, 0, 0])
///             .with_name("sin(0.01t)")
///             .with_marker(rerun::components::MarkerShape::Circle)
///             .with_marker_size(4.0),
///     )?;
///     rec.log_static(
///         "trig/cos",
///         &rerun::SeriesPoint::new()
///             .with_color([0, 255, 0])
///             .with_name("cos(0.01t)")
///             .with_marker(rerun::components::MarkerShape::Cross)
///             .with_marker_size(2.0),
///     )?;
///
///     for t in 0..((std::f32::consts::TAU * 2.0 * 10.0) as i64) {
///         rec.set_time_sequence("step", t);
///
///         // Log two time series under a shared root so that they show in the same plot by default.
///         rec.log("trig/sin", &rerun::Scalar::new((t as f64 / 10.0).sin()))?;
///         rec.log("trig/cos", &rerun::Scalar::new((t as f64 / 10.0).cos()))?;
///     }
///
///     Ok(())
/// }
/// ```
/// <center>
/// <picture>
///   <source media="(max-width: 480px)" srcset="https://static.rerun.io/series_point_style/82207a705da6c086b28ce161db1db9e8b12258b7/480w.png">
///   <source media="(max-width: 768px)" srcset="https://static.rerun.io/series_point_style/82207a705da6c086b28ce161db1db9e8b12258b7/768w.png">
///   <source media="(max-width: 1024px)" srcset="https://static.rerun.io/series_point_style/82207a705da6c086b28ce161db1db9e8b12258b7/1024w.png">
///   <source media="(max-width: 1200px)" srcset="https://static.rerun.io/series_point_style/82207a705da6c086b28ce161db1db9e8b12258b7/1200w.png">
///   <img src="https://static.rerun.io/series_point_style/82207a705da6c086b28ce161db1db9e8b12258b7/full.png" width="640">
/// </picture>
/// </center>
#[derive(Clone, Debug)]
pub struct SeriesPoint {
    /// Color for the corresponding series.
    pub color: Option<crate::components::Color>,

    /// What shape to use to represent the point
    pub marker: Option<crate::components::MarkerShape>,

    /// Display name of the series.
    ///
    /// Used in the legend.
    pub name: Option<crate::components::Name>,

    /// Size of the marker.
    pub marker_size: Option<crate::components::MarkerSize>,
}

impl SeriesPoint {
    /// Returns the [`ComponentDescriptor`] for [`Self::color`].
    #[inline]
    pub fn descriptor_color() -> ComponentDescriptor {
        ComponentDescriptor {
            archetype_name: Some("rerun.archetypes.SeriesPoint".into()),
            component_name: "rerun.components.Color".into(),
            archetype_field_name: Some("color".into()),
        }
    }

    /// Returns the [`ComponentDescriptor`] for [`Self::marker`].
    #[inline]
    pub fn descriptor_marker() -> ComponentDescriptor {
        ComponentDescriptor {
            archetype_name: Some("rerun.archetypes.SeriesPoint".into()),
            component_name: "rerun.components.MarkerShape".into(),
            archetype_field_name: Some("marker".into()),
        }
    }

    /// Returns the [`ComponentDescriptor`] for [`Self::name`].
    #[inline]
    pub fn descriptor_name() -> ComponentDescriptor {
        ComponentDescriptor {
            archetype_name: Some("rerun.archetypes.SeriesPoint".into()),
            component_name: "rerun.components.Name".into(),
            archetype_field_name: Some("name".into()),
        }
    }

    /// Returns the [`ComponentDescriptor`] for [`Self::marker_size`].
    #[inline]
    pub fn descriptor_marker_size() -> ComponentDescriptor {
        ComponentDescriptor {
            archetype_name: Some("rerun.archetypes.SeriesPoint".into()),
            component_name: "rerun.components.MarkerSize".into(),
            archetype_field_name: Some("marker_size".into()),
        }
    }

    /// Returns the [`ComponentDescriptor`] for the associated indicator component.
    #[inline]
    pub fn descriptor_indicator() -> ComponentDescriptor {
        ComponentDescriptor {
            archetype_name: Some("rerun.archetypes.SeriesPoint".into()),
            component_name: "rerun.components.SeriesPointIndicator".into(),
            archetype_field_name: None,
        }
    }
}

static REQUIRED_COMPONENTS: once_cell::sync::Lazy<[ComponentDescriptor; 0usize]> =
    once_cell::sync::Lazy::new(|| []);

static RECOMMENDED_COMPONENTS: once_cell::sync::Lazy<[ComponentDescriptor; 1usize]> =
    once_cell::sync::Lazy::new(|| [SeriesPoint::descriptor_indicator()]);

static OPTIONAL_COMPONENTS: once_cell::sync::Lazy<[ComponentDescriptor; 4usize]> =
    once_cell::sync::Lazy::new(|| {
        [
            SeriesPoint::descriptor_color(),
            SeriesPoint::descriptor_marker(),
            SeriesPoint::descriptor_name(),
            SeriesPoint::descriptor_marker_size(),
        ]
    });

static ALL_COMPONENTS: once_cell::sync::Lazy<[ComponentDescriptor; 5usize]> =
    once_cell::sync::Lazy::new(|| {
        [
            SeriesPoint::descriptor_indicator(),
            SeriesPoint::descriptor_color(),
            SeriesPoint::descriptor_marker(),
            SeriesPoint::descriptor_name(),
            SeriesPoint::descriptor_marker_size(),
        ]
    });

impl SeriesPoint {
    /// The total number of components in the archetype: 0 required, 1 recommended, 4 optional
    pub const NUM_COMPONENTS: usize = 5usize;
}

/// Indicator component for the [`SeriesPoint`] [`::re_types_core::Archetype`]
pub type SeriesPointIndicator = ::re_types_core::GenericIndicatorComponent<SeriesPoint>;

impl ::re_types_core::Archetype for SeriesPoint {
    type Indicator = SeriesPointIndicator;

    #[inline]
    fn name() -> ::re_types_core::ArchetypeName {
        "rerun.archetypes.SeriesPoint".into()
    }

    #[inline]
    fn display_name() -> &'static str {
        "Series point"
    }

    #[inline]
    fn indicator() -> ComponentBatchCowWithDescriptor<'static> {
        static INDICATOR: SeriesPointIndicator = SeriesPointIndicator::DEFAULT;
        ComponentBatchCowWithDescriptor::new(&INDICATOR as &dyn ::re_types_core::ComponentBatch)
    }

    #[inline]
    fn required_components() -> ::std::borrow::Cow<'static, [ComponentDescriptor]> {
        REQUIRED_COMPONENTS.as_slice().into()
    }

    #[inline]
    fn recommended_components() -> ::std::borrow::Cow<'static, [ComponentDescriptor]> {
        RECOMMENDED_COMPONENTS.as_slice().into()
    }

    #[inline]
    fn optional_components() -> ::std::borrow::Cow<'static, [ComponentDescriptor]> {
        OPTIONAL_COMPONENTS.as_slice().into()
    }

    #[inline]
    fn all_components() -> ::std::borrow::Cow<'static, [ComponentDescriptor]> {
        ALL_COMPONENTS.as_slice().into()
    }

    #[inline]
    fn from_arrow_components(
        arrow_data: impl IntoIterator<Item = (ComponentDescriptor, arrow::array::ArrayRef)>,
    ) -> DeserializationResult<Self> {
        re_tracing::profile_function!();
        use ::re_types_core::{Loggable as _, ResultExt as _};
        let arrays_by_descr: ::nohash_hasher::IntMap<_, _> = arrow_data.into_iter().collect();
        let color = if let Some(array) = arrays_by_descr.get(&Self::descriptor_color()) {
            <crate::components::Color>::from_arrow_opt(&**array)
                .with_context("rerun.archetypes.SeriesPoint#color")?
                .into_iter()
                .next()
                .flatten()
        } else {
            None
        };
        let marker = if let Some(array) = arrays_by_descr.get(&Self::descriptor_marker()) {
            <crate::components::MarkerShape>::from_arrow_opt(&**array)
                .with_context("rerun.archetypes.SeriesPoint#marker")?
                .into_iter()
                .next()
                .flatten()
        } else {
            None
        };
        let name = if let Some(array) = arrays_by_descr.get(&Self::descriptor_name()) {
            <crate::components::Name>::from_arrow_opt(&**array)
                .with_context("rerun.archetypes.SeriesPoint#name")?
                .into_iter()
                .next()
                .flatten()
        } else {
            None
        };
        let marker_size = if let Some(array) = arrays_by_descr.get(&Self::descriptor_marker_size())
        {
            <crate::components::MarkerSize>::from_arrow_opt(&**array)
                .with_context("rerun.archetypes.SeriesPoint#marker_size")?
                .into_iter()
                .next()
                .flatten()
        } else {
            None
        };
        Ok(Self {
            color,
            marker,
            name,
            marker_size,
        })
    }
}

impl ::re_types_core::AsComponents for SeriesPoint {
    fn as_component_batches(&self) -> Vec<ComponentBatchCowWithDescriptor<'_>> {
        re_tracing::profile_function!();
        use ::re_types_core::Archetype as _;
        [
            Some(Self::indicator()),
            (self
                .color
                .as_ref()
                .map(|comp| (comp as &dyn ComponentBatch)))
            .map(|batch| ::re_types_core::ComponentBatchCowWithDescriptor {
                batch: batch.into(),
                descriptor_override: Some(Self::descriptor_color()),
            }),
            (self
                .marker
                .as_ref()
                .map(|comp| (comp as &dyn ComponentBatch)))
            .map(|batch| ::re_types_core::ComponentBatchCowWithDescriptor {
                batch: batch.into(),
                descriptor_override: Some(Self::descriptor_marker()),
            }),
            (self.name.as_ref().map(|comp| (comp as &dyn ComponentBatch))).map(|batch| {
                ::re_types_core::ComponentBatchCowWithDescriptor {
                    batch: batch.into(),
                    descriptor_override: Some(Self::descriptor_name()),
                }
            }),
            (self
                .marker_size
                .as_ref()
                .map(|comp| (comp as &dyn ComponentBatch)))
            .map(|batch| ::re_types_core::ComponentBatchCowWithDescriptor {
                batch: batch.into(),
                descriptor_override: Some(Self::descriptor_marker_size()),
            }),
        ]
        .into_iter()
        .flatten()
        .collect()
    }
}

impl ::re_types_core::ArchetypeReflectionMarker for SeriesPoint {}

impl SeriesPoint {
    /// Create a new `SeriesPoint`.
    #[inline]
    pub fn new() -> Self {
        Self {
            color: None,
            marker: None,
            name: None,
            marker_size: None,
        }
    }

    /// Color for the corresponding series.
    #[inline]
    pub fn with_color(mut self, color: impl Into<crate::components::Color>) -> Self {
        self.color = Some(color.into());
        self
    }

    /// What shape to use to represent the point
    #[inline]
    pub fn with_marker(mut self, marker: impl Into<crate::components::MarkerShape>) -> Self {
        self.marker = Some(marker.into());
        self
    }

    /// Display name of the series.
    ///
    /// Used in the legend.
    #[inline]
    pub fn with_name(mut self, name: impl Into<crate::components::Name>) -> Self {
        self.name = Some(name.into());
        self
    }

    /// Size of the marker.
    #[inline]
    pub fn with_marker_size(
        mut self,
        marker_size: impl Into<crate::components::MarkerSize>,
    ) -> Self {
        self.marker_size = Some(marker_size.into());
        self
    }
}

impl ::re_byte_size::SizeBytes for SeriesPoint {
    #[inline]
    fn heap_size_bytes(&self) -> u64 {
        self.color.heap_size_bytes()
            + self.marker.heap_size_bytes()
            + self.name.heap_size_bytes()
            + self.marker_size.heap_size_bytes()
    }

    #[inline]
    fn is_pod() -> bool {
        <Option<crate::components::Color>>::is_pod()
            && <Option<crate::components::MarkerShape>>::is_pod()
            && <Option<crate::components::Name>>::is_pod()
            && <Option<crate::components::MarkerSize>>::is_pod()
    }
}
