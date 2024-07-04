// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/archetypes/arrows2d.fbs".

#pragma once

#include "../collection.hpp"
#include "../compiler_utils.hpp"
#include "../components/class_id.hpp"
#include "../components/color.hpp"
#include "../components/draw_order.hpp"
#include "../components/position2d.hpp"
#include "../components/radius.hpp"
#include "../components/text.hpp"
#include "../components/vector2d.hpp"
#include "../data_cell.hpp"
#include "../indicator_component.hpp"
#include "../result.hpp"

#include <cstdint>
#include <optional>
#include <utility>
#include <vector>

namespace rerun::archetypes {
    /// **Archetype**: 2D arrows with optional colors, radii, labels, etc.
    ///
    /// ## Example
    ///
    /// ### Simple batch of 2D arrows
    /// ![image](https://static.rerun.io/arrow2d_simple/59f044ccc03f7bc66ee802288f75706618b29a6e/full.png)
    ///
    /// ```cpp
    /// #include <rerun.hpp>
    ///
    /// int main() {
    ///     const auto rec = rerun::RecordingStream("rerun_example_arrow2d");
    ///     rec.spawn().exit_on_failure();
    ///
    ///     rec.log(
    ///         "arrows",
    ///         rerun::Arrows2D::from_vectors({{1.0f, 0.0f}, {0.0f, -1.0f}, {-0.7f, 0.7f}})
    ///             .with_radii(0.025f)
    ///             .with_origins({{0.25f, 0.0f}, {0.25f, 0.0f}, {-0.1f, -0.1f}})
    ///             .with_colors({{255, 0, 0}, {0, 255, 0}, {127, 0, 255}})
    ///             .with_labels({"right", "up", "left-down"})
    ///     );
    /// }
    /// ```
    struct Arrows2D {
        /// All the vectors for each arrow in the batch.
        Collection<rerun::components::Vector2D> vectors;

        /// All the origin (base) positions for each arrow in the batch.
        ///
        /// If no origins are set, (0, 0) is used as the origin for each arrow.
        std::optional<Collection<rerun::components::Position2D>> origins;

        /// Optional radii for the arrows.
        ///
        /// The shaft is rendered as a line with `radius = 0.5 * radius`.
        /// The tip is rendered with `height = 2.0 * radius` and `radius = 1.0 * radius`.
        std::optional<Collection<rerun::components::Radius>> radii;

        /// Optional colors for the points.
        std::optional<Collection<rerun::components::Color>> colors;

        /// Optional text labels for the arrows.
        ///
        /// If there's a single label present, it will be placed at the center of the entity.
        /// Otherwise, each instance will have its own label.
        std::optional<Collection<rerun::components::Text>> labels;

        /// An optional floating point value that specifies the 2D drawing order.
        ///
        /// Objects with higher values are drawn on top of those with lower values.
        std::optional<rerun::components::DrawOrder> draw_order;

        /// Optional class Ids for the points.
        ///
        /// The class ID provides colors and labels if not specified explicitly.
        std::optional<Collection<rerun::components::ClassId>> class_ids;

      public:
        static constexpr const char IndicatorComponentName[] = "rerun.components.Arrows2DIndicator";

        /// Indicator component, used to identify the archetype when converting to a list of components.
        using IndicatorComponent = rerun::components::IndicatorComponent<IndicatorComponentName>;

      public:
        // Extensions to generated type defined in 'arrows2d_ext.cpp'

        /// Creates new 2D arrows pointing in the given directions, with a base at the origin (0, 0).
        static Arrows2D from_vectors(Collection<components::Vector2D> vectors_) {
            Arrows2D arrows;
            arrows.vectors = std::move(vectors_);
            return arrows;
        }

      public:
        Arrows2D() = default;
        Arrows2D(Arrows2D&& other) = default;

        /// All the origin (base) positions for each arrow in the batch.
        ///
        /// If no origins are set, (0, 0) is used as the origin for each arrow.
        Arrows2D with_origins(Collection<rerun::components::Position2D> _origins) && {
            origins = std::move(_origins);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RR_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Optional radii for the arrows.
        ///
        /// The shaft is rendered as a line with `radius = 0.5 * radius`.
        /// The tip is rendered with `height = 2.0 * radius` and `radius = 1.0 * radius`.
        Arrows2D with_radii(Collection<rerun::components::Radius> _radii) && {
            radii = std::move(_radii);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RR_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Optional colors for the points.
        Arrows2D with_colors(Collection<rerun::components::Color> _colors) && {
            colors = std::move(_colors);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RR_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Optional text labels for the arrows.
        ///
        /// If there's a single label present, it will be placed at the center of the entity.
        /// Otherwise, each instance will have its own label.
        Arrows2D with_labels(Collection<rerun::components::Text> _labels) && {
            labels = std::move(_labels);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RR_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// An optional floating point value that specifies the 2D drawing order.
        ///
        /// Objects with higher values are drawn on top of those with lower values.
        Arrows2D with_draw_order(rerun::components::DrawOrder _draw_order) && {
            draw_order = std::move(_draw_order);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RR_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }

        /// Optional class Ids for the points.
        ///
        /// The class ID provides colors and labels if not specified explicitly.
        Arrows2D with_class_ids(Collection<rerun::components::ClassId> _class_ids) && {
            class_ids = std::move(_class_ids);
            // See: https://github.com/rerun-io/rerun/issues/4027
            RR_WITH_MAYBE_UNINITIALIZED_DISABLED(return std::move(*this);)
        }
    };

} // namespace rerun::archetypes

namespace rerun {
    /// \private
    template <typename T>
    struct AsComponents;

    /// \private
    template <>
    struct AsComponents<archetypes::Arrows2D> {
        /// Serialize all set component batches.
        static Result<std::vector<DataCell>> serialize(const archetypes::Arrows2D& archetype);
    };
} // namespace rerun
