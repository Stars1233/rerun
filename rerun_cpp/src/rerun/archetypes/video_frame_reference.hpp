// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/archetypes/video_frame_reference.fbs".

#pragma once

#include "../collection.hpp"
#include "../compiler_utils.hpp"
#include "../component_batch.hpp"
#include "../components/entity_path.hpp"
#include "../components/video_timestamp.hpp"
#include "../indicator_component.hpp"
#include "../result.hpp"

#include <cstdint>
#include <optional>
#include <utility>
#include <vector>

namespace rerun::archetypes {
    /// **Archetype**: References a single video frame.
    ///
    /// Used to display individual video frames from a `archetypes::AssetVideo`.
    /// To show an entire video, a fideo frame reference for each frame of the video should be logged.
    ///
    /// ## Examples
    ///
    /// ### Video with automatically determined frames
    /// ![image](https://static.rerun.io/video_manual_frames/320a44e1e06b8b3a3161ecbbeae3e04d1ccb9589/full.png)
    ///
    /// ```cpp
    /// #include <rerun.hpp>
    ///
    /// #include <iostream>
    ///
    /// using namespace std::chrono_literals;
    ///
    /// int main(int argc, char* argv[]) {
    ///     if (argc <2) {
    ///         // TODO(#7354): Only mp4 is supported for now.
    ///         std::cerr <<"Usage: " <<argv[0] <<" <path_to_video.[mp4]>" <<std::endl;
    ///         return 1;
    ///     }
    ///
    ///     const auto path = argv[1];
    ///
    ///     const auto rec = rerun::RecordingStream("rerun_example_asset_video_auto_frames");
    ///     rec.spawn().exit_on_failure();
    ///
    ///     // Log video asset which is referred to by frame references.
    ///     auto video_asset = rerun::AssetVideo::from_file(path).value_or_throw();
    ///     rec.log_static("video", video_asset);
    ///
    ///     // Send automatically determined video frame timestamps.
    ///     std::vector<std::chrono::nanoseconds> frame_timestamps_ns =
    ///         video_asset.read_frame_timestamps_ns().value_or_throw();
    ///     // Note timeline values don't have to be the same as the video timestamps.
    ///     auto time_column =
    ///         rerun::TimeColumn::from_times("video_time", rerun::borrow(frame_timestamps_ns));
    ///
    ///     std::vector<rerun::components::VideoTimestamp> video_timestamps(frame_timestamps_ns.size());
    ///     for (size_t i = 0; i <frame_timestamps_ns.size(); i++) {
    ///         video_timestamps[i] = rerun::components::VideoTimestamp(frame_timestamps_ns[i]);
    ///     }
    ///     auto video_frame_reference_indicators =
    ///         rerun::ComponentColumn::from_indicators<rerun::VideoFrameReference>(
    ///             static_cast<uint32_t>(video_timestamps.size())
    ///         );
    ///
    ///     rec.send_columns(
    ///         "video",
    ///         time_column,
    ///         {
    ///             video_frame_reference_indicators.value_or_throw(),
    ///             rerun::ComponentColumn::from_loggable(rerun::borrow(video_timestamps)).value_or_throw(),
    ///         }
    ///     );
    /// }
    /// ```
    ///
    /// ### Demonstrates manual use of video frame references
    /// ![image](https://static.rerun.io/video_manual_frames/320a44e1e06b8b3a3161ecbbeae3e04d1ccb9589/full.png)
    ///
    /// ```cpp
    /// #include <rerun.hpp>
    ///
    /// #include <iostream>
    ///
    /// using namespace std::chrono_literals;
    ///
    /// int main(int argc, char* argv[]) {
    ///     if (argc <2) {
    ///         // TODO(#7354): Only mp4 is supported for now.
    ///         std::cerr <<"Usage: " <<argv[0] <<" <path_to_video.[mp4]>" <<std::endl;
    ///         return 1;
    ///     }
    ///
    ///     const auto path = argv[1];
    ///
    ///     const auto rec = rerun::RecordingStream("rerun_example_asset_video_manual_frames");
    ///     rec.spawn().exit_on_failure();
    ///
    ///     // Log video asset which is referred to by frame references.
    ///     rec.log_static("video_asset", rerun::AssetVideo::from_file(path).value_or_throw());
    ///
    ///     // Create two entities, showing the same video frozen at different times.
    ///     rec.log("frame_at_start", rerun::VideoFrameReference(0.0s).with_video_reference("video_asset"));
    ///     rec.log(
    ///         "frame_at_one_second",
    ///         rerun::VideoFrameReference(1.0s).with_video_reference("video_asset")
    ///     );
    ///
    ///     // TODO(#5520): log blueprint once supported
    /// }
    /// ```
    ///
    /// ⚠ **This is an experimental API! It is not fully supported, and is likely to change significantly in future versions.**
    struct VideoFrameReference {
        /// References the closest video frame to this timestamp.
        ///
        /// Note that this uses the closest video frame instead of the latest at this timestamp
        /// in order to be more forgiving of rounding errors for inprecise timestamp types.
        rerun::components::VideoTimestamp timestamp;

        /// Optional reference to an entity with a `archetypes::AssetVideo`.
        ///
        /// If none is specified, the video is assumed to be at the same entity.
        /// Note that blueprint overrides on the referenced video will be ignored regardless,
        /// as this is always interpreted as a reference to the data store.
        ///
        /// For a series of video frame references, it is recommended to specify this path only once
        /// at the beginning of the series and then rely on latest-at query semantics to
        /// keep the video reference active.
        std::optional<rerun::components::EntityPath> video_reference;

      public:
        static constexpr const char IndicatorComponentName[] =
            "rerun.components.VideoFrameReferenceIndicator";

        /// Indicator component, used to identify the archetype when converting to a list of components.
        using IndicatorComponent = rerun::components::IndicatorComponent<IndicatorComponentName>;

      public:
        VideoFrameReference() = default;
        VideoFrameReference(VideoFrameReference&& other) = default;

        explicit VideoFrameReference(rerun::components::VideoTimestamp _timestamp)
            : timestamp(std::move(_timestamp)) {}

        /// Optional reference to an entity with a `archetypes::AssetVideo`.
        ///
        /// If none is specified, the video is assumed to be at the same entity.
        /// Note that blueprint overrides on the referenced video will be ignored regardless,
        /// as this is always interpreted as a reference to the data store.
        ///
        /// For a series of video frame references, it is recommended to specify this path only once
        /// at the beginning of the series and then rely on latest-at query semantics to
        /// keep the video reference active.
        VideoFrameReference with_video_reference(rerun::components::EntityPath _video_reference
        ) && {
            video_reference = std::move(_video_reference);
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
    struct AsComponents<archetypes::VideoFrameReference> {
        /// Serialize all set component batches.
        static Result<std::vector<ComponentBatch>> serialize(
            const archetypes::VideoFrameReference& archetype
        );
    };
} // namespace rerun
