// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/blueprint/components/visual_bounds2d.fbs".

#pragma once

#include "../../datatypes/range2d.hpp"
#include "../../result.hpp"

#include <cstdint>
#include <memory>

namespace rerun::blueprint::components {
    /// **Component**: Visual bounds in 2D space used for `Spatial2DView`.
    ///
    /// ⚠ **This type is _unstable_ and may change significantly in a way that the data won't be backwards compatible.**
    ///
    struct VisualBounds2D {
        /// X and y ranges that should be visible.
        rerun::datatypes::Range2D range2d;

      public:
        VisualBounds2D() = default;

        VisualBounds2D(rerun::datatypes::Range2D range2d_) : range2d(range2d_) {}

        VisualBounds2D& operator=(rerun::datatypes::Range2D range2d_) {
            range2d = range2d_;
            return *this;
        }

        /// Cast to the underlying Range2D datatype
        operator rerun::datatypes::Range2D() const {
            return range2d;
        }
    };
} // namespace rerun::blueprint::components

namespace rerun {
    static_assert(
        sizeof(rerun::datatypes::Range2D) == sizeof(blueprint::components::VisualBounds2D)
    );

    /// \private
    template <>
    struct Loggable<blueprint::components::VisualBounds2D> {
        static constexpr std::string_view ComponentType =
            "rerun.blueprint.components.VisualBounds2D";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype() {
            return Loggable<rerun::datatypes::Range2D>::arrow_datatype();
        }

        /// Serializes an array of `rerun::blueprint:: components::VisualBounds2D` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const blueprint::components::VisualBounds2D* instances, size_t num_instances
        ) {
            if (num_instances == 0) {
                return Loggable<rerun::datatypes::Range2D>::to_arrow(nullptr, 0);
            } else if (instances == nullptr) {
                return rerun::Error(
                    ErrorCode::UnexpectedNullArgument,
                    "Passed array instances is null when num_elements> 0."
                );
            } else {
                return Loggable<rerun::datatypes::Range2D>::to_arrow(
                    &instances->range2d,
                    num_instances
                );
            }
        }
    };
} // namespace rerun
