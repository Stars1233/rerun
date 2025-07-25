---
title: Micro Batching
order: 700
---


The Rerun SDK automatically handles micro-batching in a background thread in order to find a sweet spot between latency and throughput, reducing metadata overhead and thus improving both bandwidth and CPU usage.

The flushing is triggered by both time and space thresholds, whichever happens to trigger first.

This is very similar to, and has many parallels with, the [compaction mechanism running on the datastore side](../store-compaction.md).

You can configure these thresholds using the following environment variables:

#### RERUN_FLUSH_TICK_SECS

Sets the duration of the periodic tick that triggers the time threshold, in seconds.

Defaults to `RERUN_FLUSH_TICK_SECS=0.2` (200ms) unless the recording stream uses a
a networking sink which defaults to `RERUN_FLUSH_TICK_SECS=0.008` (8ms).

#### RERUN_FLUSH_NUM_BYTES

Sets the size limit that triggers the space threshold, in bytes.

Defaults to `RERUN_FLUSH_NUM_BYTES=1048576` (1MiB).

#### RERUN_FLUSH_NUM_ROWS

Sets the number of rows that drives the space threshold.

Defaults to `RERUN_FLUSH_NUM_BYTES=18446744073709551615` (`u64::MAX`).

Or directly from code, in Python & Rust:

snippet: howto/micro_batching
