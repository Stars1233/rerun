// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/rust/api.rs
// Based on "crates/store/re_types/definitions/rerun/components/aggregation_policy.fbs".

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
#![allow(non_camel_case_types)]

use ::re_types_core::external::arrow2;
use ::re_types_core::ComponentName;
use ::re_types_core::SerializationResult;
use ::re_types_core::{ComponentBatch, MaybeOwnedComponentBatch};
use ::re_types_core::{DeserializationError, DeserializationResult};

/// **Component**: Policy for aggregation of multiple scalar plot values.
///
/// This is used for lines in plots when the X axis distance of individual points goes below a single pixel,
/// i.e. a single pixel covers more than one tick worth of data. It can greatly improve performance
/// (and readability) in such situations as it prevents overdraw.
#[derive(Clone, Copy, Debug, Hash, PartialEq, Eq, Default)]
#[repr(u8)]
pub enum AggregationPolicy {
    /// No aggregation.
    Off = 1,

    /// Average all points in the range together.
    Average = 2,

    /// Keep only the maximum values in the range.
    Max = 3,

    /// Keep only the minimum values in the range.
    Min = 4,

    /// Keep both the minimum and maximum values in the range.
    ///
    /// This will yield two aggregated points instead of one, effectively creating a vertical line.
    #[default]
    MinMax = 5,

    /// Find both the minimum and maximum values in the range, then use the average of those.
    MinMaxAverage = 6,
}

impl ::re_types_core::reflection::Enum for AggregationPolicy {
    #[inline]
    fn variants() -> &'static [Self] {
        &[
            Self::Off,
            Self::Average,
            Self::Max,
            Self::Min,
            Self::MinMax,
            Self::MinMaxAverage,
        ]
    }

    #[inline]
    fn docstring_md(self) -> &'static str {
        match self {
            Self::Off => "No aggregation.",
            Self::Average => "Average all points in the range together.",
            Self::Max => "Keep only the maximum values in the range.",
            Self::Min => "Keep only the minimum values in the range.",
            Self::MinMax => {
                "Keep both the minimum and maximum values in the range.\n\nThis will yield two aggregated points instead of one, effectively creating a vertical line."
            }
            Self::MinMaxAverage => {
                "Find both the minimum and maximum values in the range, then use the average of those."
            }
        }
    }
}

impl ::re_types_core::SizeBytes for AggregationPolicy {
    #[inline]
    fn heap_size_bytes(&self) -> u64 {
        0
    }

    #[inline]
    fn is_pod() -> bool {
        true
    }
}

impl std::fmt::Display for AggregationPolicy {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::Off => write!(f, "Off"),
            Self::Average => write!(f, "Average"),
            Self::Max => write!(f, "Max"),
            Self::Min => write!(f, "Min"),
            Self::MinMax => write!(f, "MinMax"),
            Self::MinMaxAverage => write!(f, "MinMaxAverage"),
        }
    }
}

::re_types_core::macros::impl_into_cow!(AggregationPolicy);

impl ::re_types_core::Loggable for AggregationPolicy {
    #[inline]
    fn arrow_datatype() -> arrow::datatypes::DataType {
        #![allow(clippy::wildcard_imports)]
        use arrow::datatypes::*;
        DataType::UInt8
    }

    fn to_arrow2_opt<'a>(
        data: impl IntoIterator<Item = Option<impl Into<::std::borrow::Cow<'a, Self>>>>,
    ) -> SerializationResult<Box<dyn arrow2::array::Array>>
    where
        Self: Clone + 'a,
    {
        #![allow(clippy::wildcard_imports)]
        #![allow(clippy::manual_is_variant_and)]
        use ::re_types_core::{Loggable as _, ResultExt as _};
        use arrow::datatypes::*;
        use arrow2::array::*;
        Ok({
            let (somes, data0): (Vec<_>, Vec<_>) = data
                .into_iter()
                .map(|datum| {
                    let datum: Option<::std::borrow::Cow<'a, Self>> = datum.map(Into::into);
                    let datum = datum.map(|datum| *datum as u8);
                    (datum.is_some(), datum)
                })
                .unzip();
            let data0_bitmap: Option<arrow2::bitmap::Bitmap> = {
                let any_nones = somes.iter().any(|some| !*some);
                any_nones.then(|| somes.into())
            };
            PrimitiveArray::new(
                Self::arrow_datatype().into(),
                data0.into_iter().map(|v| v.unwrap_or_default()).collect(),
                data0_bitmap,
            )
            .boxed()
        })
    }

    fn from_arrow2_opt(
        arrow_data: &dyn arrow2::array::Array,
    ) -> DeserializationResult<Vec<Option<Self>>>
    where
        Self: Sized,
    {
        #![allow(clippy::wildcard_imports)]
        use ::re_types_core::{Loggable as _, ResultExt as _};
        use arrow::datatypes::*;
        use arrow2::{array::*, buffer::*};
        Ok(arrow_data
            .as_any()
            .downcast_ref::<UInt8Array>()
            .ok_or_else(|| {
                let expected = Self::arrow_datatype();
                let actual = arrow_data.data_type().clone();
                DeserializationError::datatype_mismatch(expected, actual)
            })
            .with_context("rerun.components.AggregationPolicy#enum")?
            .into_iter()
            .map(|opt| opt.copied())
            .map(|typ| match typ {
                Some(1) => Ok(Some(Self::Off)),
                Some(2) => Ok(Some(Self::Average)),
                Some(3) => Ok(Some(Self::Max)),
                Some(4) => Ok(Some(Self::Min)),
                Some(5) => Ok(Some(Self::MinMax)),
                Some(6) => Ok(Some(Self::MinMaxAverage)),
                None => Ok(None),
                Some(invalid) => Err(DeserializationError::missing_union_arm(
                    Self::arrow_datatype(),
                    "<invalid>",
                    invalid as _,
                )),
            })
            .collect::<DeserializationResult<Vec<Option<_>>>>()
            .with_context("rerun.components.AggregationPolicy")?)
    }
}

impl ::re_types_core::Component for AggregationPolicy {
    #[inline]
    fn name() -> ComponentName {
        "rerun.components.AggregationPolicy".into()
    }
}
