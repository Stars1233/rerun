// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/rust/api.rs
// Based on "crates/store/re_types/definitions/rerun/blueprint/archetypes/force_position.fbs".

#![allow(unused_braces)]
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

use ::re_types_core::try_serialize_field;
use ::re_types_core::SerializationResult;
use ::re_types_core::{ComponentBatch as _, SerializedComponentBatch};
use ::re_types_core::{ComponentDescriptor, ComponentType};
use ::re_types_core::{DeserializationError, DeserializationResult};

/// **Archetype**: Similar to gravity, this force pulls nodes towards a specific position.
///
/// ⚠️ **This type is _unstable_ and may change significantly in a way that the data won't be backwards compatible.**
#[derive(Clone, Debug, Default)]
pub struct ForcePosition {
    /// Whether the position force is enabled.
    ///
    /// The position force pulls nodes towards a specific position, similar to gravity.
    pub enabled: Option<SerializedComponentBatch>,

    /// The strength of the force.
    pub strength: Option<SerializedComponentBatch>,

    /// The position where the nodes should be pulled towards.
    pub position: Option<SerializedComponentBatch>,
}

impl ForcePosition {
    /// Returns the [`ComponentDescriptor`] for [`Self::enabled`].
    ///
    /// The corresponding component is [`crate::blueprint::components::Enabled`].
    #[inline]
    pub fn descriptor_enabled() -> ComponentDescriptor {
        ComponentDescriptor {
            archetype: Some("rerun.blueprint.archetypes.ForcePosition".into()),
            component: "ForcePosition:enabled".into(),
            component_type: Some("rerun.blueprint.components.Enabled".into()),
        }
    }

    /// Returns the [`ComponentDescriptor`] for [`Self::strength`].
    ///
    /// The corresponding component is [`crate::blueprint::components::ForceStrength`].
    #[inline]
    pub fn descriptor_strength() -> ComponentDescriptor {
        ComponentDescriptor {
            archetype: Some("rerun.blueprint.archetypes.ForcePosition".into()),
            component: "ForcePosition:strength".into(),
            component_type: Some("rerun.blueprint.components.ForceStrength".into()),
        }
    }

    /// Returns the [`ComponentDescriptor`] for [`Self::position`].
    ///
    /// The corresponding component is [`crate::components::Position2D`].
    #[inline]
    pub fn descriptor_position() -> ComponentDescriptor {
        ComponentDescriptor {
            archetype: Some("rerun.blueprint.archetypes.ForcePosition".into()),
            component: "ForcePosition:position".into(),
            component_type: Some("rerun.components.Position2D".into()),
        }
    }
}

static REQUIRED_COMPONENTS: once_cell::sync::Lazy<[ComponentDescriptor; 0usize]> =
    once_cell::sync::Lazy::new(|| []);

static RECOMMENDED_COMPONENTS: once_cell::sync::Lazy<[ComponentDescriptor; 0usize]> =
    once_cell::sync::Lazy::new(|| []);

static OPTIONAL_COMPONENTS: once_cell::sync::Lazy<[ComponentDescriptor; 3usize]> =
    once_cell::sync::Lazy::new(|| {
        [
            ForcePosition::descriptor_enabled(),
            ForcePosition::descriptor_strength(),
            ForcePosition::descriptor_position(),
        ]
    });

static ALL_COMPONENTS: once_cell::sync::Lazy<[ComponentDescriptor; 3usize]> =
    once_cell::sync::Lazy::new(|| {
        [
            ForcePosition::descriptor_enabled(),
            ForcePosition::descriptor_strength(),
            ForcePosition::descriptor_position(),
        ]
    });

impl ForcePosition {
    /// The total number of components in the archetype: 0 required, 0 recommended, 3 optional
    pub const NUM_COMPONENTS: usize = 3usize;
}

impl ::re_types_core::Archetype for ForcePosition {
    #[inline]
    fn name() -> ::re_types_core::ArchetypeName {
        "rerun.blueprint.archetypes.ForcePosition".into()
    }

    #[inline]
    fn display_name() -> &'static str {
        "Force position"
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
        let enabled = arrays_by_descr
            .get(&Self::descriptor_enabled())
            .map(|array| SerializedComponentBatch::new(array.clone(), Self::descriptor_enabled()));
        let strength = arrays_by_descr
            .get(&Self::descriptor_strength())
            .map(|array| SerializedComponentBatch::new(array.clone(), Self::descriptor_strength()));
        let position = arrays_by_descr
            .get(&Self::descriptor_position())
            .map(|array| SerializedComponentBatch::new(array.clone(), Self::descriptor_position()));
        Ok(Self {
            enabled,
            strength,
            position,
        })
    }
}

impl ::re_types_core::AsComponents for ForcePosition {
    #[inline]
    fn as_serialized_batches(&self) -> Vec<SerializedComponentBatch> {
        use ::re_types_core::Archetype as _;
        [
            self.enabled.clone(),
            self.strength.clone(),
            self.position.clone(),
        ]
        .into_iter()
        .flatten()
        .collect()
    }
}

impl ::re_types_core::ArchetypeReflectionMarker for ForcePosition {}

impl ForcePosition {
    /// Create a new `ForcePosition`.
    #[inline]
    pub fn new() -> Self {
        Self {
            enabled: None,
            strength: None,
            position: None,
        }
    }

    /// Update only some specific fields of a `ForcePosition`.
    #[inline]
    pub fn update_fields() -> Self {
        Self::default()
    }

    /// Clear all the fields of a `ForcePosition`.
    #[inline]
    pub fn clear_fields() -> Self {
        use ::re_types_core::Loggable as _;
        Self {
            enabled: Some(SerializedComponentBatch::new(
                crate::blueprint::components::Enabled::arrow_empty(),
                Self::descriptor_enabled(),
            )),
            strength: Some(SerializedComponentBatch::new(
                crate::blueprint::components::ForceStrength::arrow_empty(),
                Self::descriptor_strength(),
            )),
            position: Some(SerializedComponentBatch::new(
                crate::components::Position2D::arrow_empty(),
                Self::descriptor_position(),
            )),
        }
    }

    /// Whether the position force is enabled.
    ///
    /// The position force pulls nodes towards a specific position, similar to gravity.
    #[inline]
    pub fn with_enabled(
        mut self,
        enabled: impl Into<crate::blueprint::components::Enabled>,
    ) -> Self {
        self.enabled = try_serialize_field(Self::descriptor_enabled(), [enabled]);
        self
    }

    /// The strength of the force.
    #[inline]
    pub fn with_strength(
        mut self,
        strength: impl Into<crate::blueprint::components::ForceStrength>,
    ) -> Self {
        self.strength = try_serialize_field(Self::descriptor_strength(), [strength]);
        self
    }

    /// The position where the nodes should be pulled towards.
    #[inline]
    pub fn with_position(mut self, position: impl Into<crate::components::Position2D>) -> Self {
        self.position = try_serialize_field(Self::descriptor_position(), [position]);
        self
    }
}

impl ::re_byte_size::SizeBytes for ForcePosition {
    #[inline]
    fn heap_size_bytes(&self) -> u64 {
        self.enabled.heap_size_bytes()
            + self.strength.heap_size_bytes()
            + self.position.heap_size_bytes()
    }
}
