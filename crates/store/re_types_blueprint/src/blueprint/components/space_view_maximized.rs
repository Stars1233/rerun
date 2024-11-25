// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/rust/api.rs
// Based on "crates/store/re_types/definitions/rerun/blueprint/components/space_view_maximized.fbs".

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

use ::re_types_core::external::arrow2;
use ::re_types_core::ComponentName;
use ::re_types_core::SerializationResult;
use ::re_types_core::{ComponentBatch, MaybeOwnedComponentBatch};
use ::re_types_core::{DeserializationError, DeserializationResult};

/// **Component**: Whether a space view is maximized.
#[derive(Clone, Debug, Default)]
#[repr(transparent)]
pub struct SpaceViewMaximized(pub crate::datatypes::Uuid);

impl ::re_types_core::SizeBytes for SpaceViewMaximized {
    #[inline]
    fn heap_size_bytes(&self) -> u64 {
        self.0.heap_size_bytes()
    }

    #[inline]
    fn is_pod() -> bool {
        <crate::datatypes::Uuid>::is_pod()
    }
}

impl<T: Into<crate::datatypes::Uuid>> From<T> for SpaceViewMaximized {
    fn from(v: T) -> Self {
        Self(v.into())
    }
}

impl std::borrow::Borrow<crate::datatypes::Uuid> for SpaceViewMaximized {
    #[inline]
    fn borrow(&self) -> &crate::datatypes::Uuid {
        &self.0
    }
}

impl std::ops::Deref for SpaceViewMaximized {
    type Target = crate::datatypes::Uuid;

    #[inline]
    fn deref(&self) -> &crate::datatypes::Uuid {
        &self.0
    }
}

impl std::ops::DerefMut for SpaceViewMaximized {
    #[inline]
    fn deref_mut(&mut self) -> &mut crate::datatypes::Uuid {
        &mut self.0
    }
}

::re_types_core::macros::impl_into_cow!(SpaceViewMaximized);

impl ::re_types_core::Loggable for SpaceViewMaximized {
    #[inline]
    fn arrow_datatype() -> arrow::datatypes::DataType {
        crate::datatypes::Uuid::arrow_datatype()
    }

    fn to_arrow2_opt<'a>(
        data: impl IntoIterator<Item = Option<impl Into<::std::borrow::Cow<'a, Self>>>>,
    ) -> SerializationResult<Box<dyn arrow2::array::Array>>
    where
        Self: Clone + 'a,
    {
        crate::datatypes::Uuid::to_arrow2_opt(data.into_iter().map(|datum| {
            datum.map(|datum| match datum.into() {
                ::std::borrow::Cow::Borrowed(datum) => ::std::borrow::Cow::Borrowed(&datum.0),
                ::std::borrow::Cow::Owned(datum) => ::std::borrow::Cow::Owned(datum.0),
            })
        }))
    }

    fn from_arrow2_opt(
        arrow_data: &dyn arrow2::array::Array,
    ) -> DeserializationResult<Vec<Option<Self>>>
    where
        Self: Sized,
    {
        crate::datatypes::Uuid::from_arrow2_opt(arrow_data)
            .map(|v| v.into_iter().map(|v| v.map(Self)).collect())
    }

    #[inline]
    fn from_arrow2(arrow_data: &dyn arrow2::array::Array) -> DeserializationResult<Vec<Self>>
    where
        Self: Sized,
    {
        crate::datatypes::Uuid::from_arrow2(arrow_data).map(|v| v.into_iter().map(Self).collect())
    }
}

impl ::re_types_core::Component for SpaceViewMaximized {
    #[inline]
    fn name() -> ComponentName {
        "rerun.blueprint.components.SpaceViewMaximized".into()
    }
}
