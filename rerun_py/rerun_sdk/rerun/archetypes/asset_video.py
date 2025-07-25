# DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/python/mod.rs
# Based on "crates/store/re_types/definitions/rerun/archetypes/asset_video.fbs".

# You can extend this class by creating a "AssetVideoExt" class in "asset_video_ext.py".

from __future__ import annotations

import numpy as np
import pyarrow as pa
from attrs import define, field

from .. import components, datatypes
from .._baseclasses import (
    Archetype,
    ComponentColumnList,
)
from ..error_utils import catch_and_log_exceptions
from .asset_video_ext import AssetVideoExt

__all__ = ["AssetVideo"]


@define(str=False, repr=False, init=False)
class AssetVideo(AssetVideoExt, Archetype):
    """
    **Archetype**: A video binary.

    Only MP4 containers are currently supported.

    See <https://rerun.io/docs/reference/video> for codec support and more general information.

    In order to display a video, you also need to log a [`archetypes.VideoFrameReference`][rerun.archetypes.VideoFrameReference] for each frame.

    Examples
    --------
    ### Video with automatically determined frames:
    ```python
    import sys

    import rerun as rr

    if len(sys.argv) < 2:
        # TODO(#7354): Only mp4 is supported for now.
        print(f"Usage: {sys.argv[0]} <path_to_video.[mp4]>")
        sys.exit(1)

    rr.init("rerun_example_asset_video_auto_frames", spawn=True)

    # Log video asset which is referred to by frame references.
    video_asset = rr.AssetVideo(path=sys.argv[1])
    rr.log("video", video_asset, static=True)

    # Send automatically determined video frame timestamps.
    frame_timestamps_ns = video_asset.read_frame_timestamps_nanos()
    rr.send_columns(
        "video",
        # Note timeline values don't have to be the same as the video timestamps.
        indexes=[rr.TimeColumn("video_time", duration=1e-9 * frame_timestamps_ns)],
        columns=rr.VideoFrameReference.columns_nanos(frame_timestamps_ns),
    )
    ```
    <center>
    <picture>
      <source media="(max-width: 480px)" srcset="https://static.rerun.io/video_manual_frames/320a44e1e06b8b3a3161ecbbeae3e04d1ccb9589/480w.png">
      <source media="(max-width: 768px)" srcset="https://static.rerun.io/video_manual_frames/320a44e1e06b8b3a3161ecbbeae3e04d1ccb9589/768w.png">
      <source media="(max-width: 1024px)" srcset="https://static.rerun.io/video_manual_frames/320a44e1e06b8b3a3161ecbbeae3e04d1ccb9589/1024w.png">
      <source media="(max-width: 1200px)" srcset="https://static.rerun.io/video_manual_frames/320a44e1e06b8b3a3161ecbbeae3e04d1ccb9589/1200w.png">
      <img src="https://static.rerun.io/video_manual_frames/320a44e1e06b8b3a3161ecbbeae3e04d1ccb9589/full.png" width="640">
    </picture>
    </center>

    ### Demonstrates manual use of video frame references:
    ```python
    import sys

    import rerun as rr
    import rerun.blueprint as rrb

    if len(sys.argv) < 2:
        # TODO(#7354): Only mp4 is supported for now.
        print(f"Usage: {sys.argv[0]} <path_to_video.[mp4]>")
        sys.exit(1)

    rr.init("rerun_example_asset_video_manual_frames", spawn=True)

    # Log video asset which is referred to by frame references.
    rr.log("video_asset", rr.AssetVideo(path=sys.argv[1]), static=True)

    # Create two entities, showing the same video frozen at different times.
    rr.log(
        "frame_1s",
        rr.VideoFrameReference(seconds=1.0, video_reference="video_asset"),
    )
    rr.log(
        "frame_2s",
        rr.VideoFrameReference(seconds=2.0, video_reference="video_asset"),
    )

    # Send blueprint that shows two 2D views next to each other.
    rr.send_blueprint(rrb.Horizontal(rrb.Spatial2DView(origin="frame_1s"), rrb.Spatial2DView(origin="frame_2s")))
    ```
    <center>
    <picture>
      <source media="(max-width: 480px)" srcset="https://static.rerun.io/video_manual_frames/9f41c00f84a98cc3f26875fba7c1d2fa2bad7151/480w.png">
      <source media="(max-width: 768px)" srcset="https://static.rerun.io/video_manual_frames/9f41c00f84a98cc3f26875fba7c1d2fa2bad7151/768w.png">
      <source media="(max-width: 1024px)" srcset="https://static.rerun.io/video_manual_frames/9f41c00f84a98cc3f26875fba7c1d2fa2bad7151/1024w.png">
      <source media="(max-width: 1200px)" srcset="https://static.rerun.io/video_manual_frames/9f41c00f84a98cc3f26875fba7c1d2fa2bad7151/1200w.png">
      <img src="https://static.rerun.io/video_manual_frames/9f41c00f84a98cc3f26875fba7c1d2fa2bad7151/full.png" width="640">
    </picture>
    </center>

    """

    # __init__ can be found in asset_video_ext.py

    def __attrs_clear__(self) -> None:
        """Convenience method for calling `__attrs_init__` with all `None`s."""
        self.__attrs_init__(
            blob=None,
            media_type=None,
        )

    @classmethod
    def _clear(cls) -> AssetVideo:
        """Produce an empty AssetVideo, bypassing `__init__`."""
        inst = cls.__new__(cls)
        inst.__attrs_clear__()
        return inst

    @classmethod
    def from_fields(
        cls,
        *,
        clear_unset: bool = False,
        blob: datatypes.BlobLike | None = None,
        media_type: datatypes.Utf8Like | None = None,
    ) -> AssetVideo:
        """
        Update only some specific fields of a `AssetVideo`.

        Parameters
        ----------
        clear_unset:
            If true, all unspecified fields will be explicitly cleared.
        blob:
            The asset's bytes.
        media_type:
            The Media Type of the asset.

            Supported values:
            * `video/mp4`

            If omitted, the viewer will try to guess from the data blob.
            If it cannot guess, it won't be able to render the asset.

        """

        inst = cls.__new__(cls)
        with catch_and_log_exceptions(context=cls.__name__):
            kwargs = {
                "blob": blob,
                "media_type": media_type,
            }

            if clear_unset:
                kwargs = {k: v if v is not None else [] for k, v in kwargs.items()}  # type: ignore[misc]

            inst.__attrs_init__(**kwargs)
            return inst

        inst.__attrs_clear__()
        return inst

    @classmethod
    def cleared(cls) -> AssetVideo:
        """Clear all the fields of a `AssetVideo`."""
        return cls.from_fields(clear_unset=True)

    @classmethod
    def columns(
        cls,
        *,
        blob: datatypes.BlobArrayLike | None = None,
        media_type: datatypes.Utf8ArrayLike | None = None,
    ) -> ComponentColumnList:
        """
        Construct a new column-oriented component bundle.

        This makes it possible to use `rr.send_columns` to send columnar data directly into Rerun.

        The returned columns will be partitioned into unit-length sub-batches by default.
        Use `ComponentColumnList.partition` to repartition the data as needed.

        Parameters
        ----------
        blob:
            The asset's bytes.
        media_type:
            The Media Type of the asset.

            Supported values:
            * `video/mp4`

            If omitted, the viewer will try to guess from the data blob.
            If it cannot guess, it won't be able to render the asset.

        """

        inst = cls.__new__(cls)
        with catch_and_log_exceptions(context=cls.__name__):
            inst.__attrs_init__(
                blob=blob,
                media_type=media_type,
            )

        batches = inst.as_component_batches()
        if len(batches) == 0:
            return ComponentColumnList([])

        kwargs = {"AssetVideo:blob": blob, "AssetVideo:media_type": media_type}
        columns = []

        for batch in batches:
            arrow_array = batch.as_arrow_array()

            # For primitive arrays and fixed size list arrays, we infer partition size from the input shape.
            if pa.types.is_primitive(arrow_array.type) or pa.types.is_fixed_size_list(arrow_array.type):
                param = kwargs[batch.component_descriptor().component]  # type: ignore[index]
                shape = np.shape(param)  # type: ignore[arg-type]
                elem_flat_len = int(np.prod(shape[1:])) if len(shape) > 1 else 1  # type: ignore[redundant-expr,misc]

                if pa.types.is_fixed_size_list(arrow_array.type) and arrow_array.type.list_size == elem_flat_len:
                    # If the product of the last dimensions of the shape are equal to the size of the fixed size list array,
                    # we have `num_rows` single element batches (each element is a fixed sized list).
                    # (This should have been already validated by conversion to the arrow_array)
                    batch_length = 1
                else:
                    batch_length = shape[1] if len(shape) > 1 else 1  # type: ignore[redundant-expr,misc]

                num_rows = shape[0] if len(shape) >= 1 else 1  # type: ignore[redundant-expr,misc]
                sizes = batch_length * np.ones(num_rows)
            else:
                # For non-primitive types, default to partitioning each element separately.
                sizes = np.ones(len(arrow_array))

            columns.append(batch.partition(sizes))

        return ComponentColumnList(columns)

    blob: components.BlobBatch | None = field(
        metadata={"component": True},
        default=None,
        converter=components.BlobBatch._converter,  # type: ignore[misc]
    )
    # The asset's bytes.
    #
    # (Docstring intentionally commented out to hide this field from the docs)

    media_type: components.MediaTypeBatch | None = field(
        metadata={"component": True},
        default=None,
        converter=components.MediaTypeBatch._converter,  # type: ignore[misc]
    )
    # The Media Type of the asset.
    #
    # Supported values:
    # * `video/mp4`
    #
    # If omitted, the viewer will try to guess from the data blob.
    # If it cannot guess, it won't be able to render the asset.
    #
    # (Docstring intentionally commented out to hide this field from the docs)

    __str__ = Archetype.__str__
    __repr__ = Archetype.__repr__  # type: ignore[assignment]
