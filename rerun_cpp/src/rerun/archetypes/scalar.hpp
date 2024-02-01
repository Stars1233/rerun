// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/archetypes/scalar.fbs".

#pragma once

#include "../collection.hpp"
#include "../compiler_utils.hpp"
#include "../components/scalar.hpp"
#include "../components/text.hpp"
#include "../data_cell.hpp"
#include "../indicator_component.hpp"
#include "../result.hpp"

#include <cstdint>
#include <optional>
#include <utility>
#include <vector>

namespace rerun::archetypes {
    /// **Archetype**: Log a double-precision scalar.
    ///
    /// The current timeline value will be used for the time/X-axis, hence scalars
    /// cannot be timeless.
    ///
    /// When used to produce a plot, this archetype is used to provide the data that
    /// is referenced by the `SeriesLine` or `SeriesPoint` archetypes. You can do
    /// this by logging both archetypes to the same path, or alternatively configuring
    /// the plot-specific archetypes through the blueprint.
    ///
    /// See also `rerun::archetypes::SeriesPoint`, `rerun::archetypes::SeriesLine`.
    ///
    /// ## Example
    ///
    /// ### Simple line plot
    /// ![image](https://static.rerun.io/scalar_simple/8bcc92f56268739f8cd24d60d1fe72a655f62a46/full.png)
    ///
    /// ```cpp
    /// #include <rerun.hpp>
    ///
    /// #include <cmath>
    ///
    /// int main() {
    ///     const auto rec = rerun::RecordingStream("rerun_example_scalar");
    ///     rec.spawn().exit_on_failure();
    ///
    ///     for (int step = 0; step <64; ++step) {
    ///         rec.set_time_sequence("step", step);
    ///         rec.log("scalar", rerun::TimeSeriesScalar(std::sin(static_cast<double>(step) / 10.0)));
    ///     }
    /// }
    /// ```
    struct Scalar {
        /// The scalar value to log.
        rerun::components::Scalar scalar;

        /// An optional label for the scalar.
        ///
        /// TODO(#1289): This won't show up on points at the moment, as our plots don't yet
        /// support displaying labels for individual points.
        std::optional<rerun::components::Text> text;

      public:
        static constexpr const char IndicatorComponentName[] = "rerun.components.ScalarIndicator";

        /// Indicator component, used to identify the archetype when converting to a list of components.
        using IndicatorComponent = rerun::components::IndicatorComponent<IndicatorComponentName>;

      public:
        Scalar() = default;
        Scalar(Scalar&& other) = default;

        explicit Scalar(rerun::components::Scalar _scalar) : scalar(std::move(_scalar)) {}

        /// An optional label for the scalar.
        ///
        /// TODO(#1289): This won't show up on points at the moment, as our plots don't yet
        /// support displaying labels for individual points.
        Scalar with_text(rerun::components::Text _text) && {
            text = std::move(_text);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RR_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Returns the number of primary instances of this archetype.
        size_t num_instances() const {
            return 1;
        }
    };

} // namespace rerun::archetypes

namespace rerun {
    /// \private
    template <typename T>
    struct AsComponents;

    /// \private
    template <>
    struct AsComponents<archetypes::Scalar> {
        /// Serialize all set component batches.
        static Result<std::vector<DataCell>> serialize(const archetypes::Scalar& archetype);
    };
} // namespace rerun
