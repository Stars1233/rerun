// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/testing/archetypes/fuzzy.fbs".

#include "affix_fuzzer2.hpp"

#include <rerun/collection_adapter_builtins.hpp>

namespace rerun::archetypes {
    AffixFuzzer2 AffixFuzzer2::clear_fields() {
        auto archetype = AffixFuzzer2();
        archetype.fuzz1101 =
            ComponentBatch::empty<rerun::components::AffixFuzzer1>(Descriptor_fuzz1101)
                .value_or_throw();
        archetype.fuzz1102 =
            ComponentBatch::empty<rerun::components::AffixFuzzer2>(Descriptor_fuzz1102)
                .value_or_throw();
        archetype.fuzz1103 =
            ComponentBatch::empty<rerun::components::AffixFuzzer3>(Descriptor_fuzz1103)
                .value_or_throw();
        archetype.fuzz1104 =
            ComponentBatch::empty<rerun::components::AffixFuzzer4>(Descriptor_fuzz1104)
                .value_or_throw();
        archetype.fuzz1105 =
            ComponentBatch::empty<rerun::components::AffixFuzzer5>(Descriptor_fuzz1105)
                .value_or_throw();
        archetype.fuzz1106 =
            ComponentBatch::empty<rerun::components::AffixFuzzer6>(Descriptor_fuzz1106)
                .value_or_throw();
        archetype.fuzz1107 =
            ComponentBatch::empty<rerun::components::AffixFuzzer7>(Descriptor_fuzz1107)
                .value_or_throw();
        archetype.fuzz1108 =
            ComponentBatch::empty<rerun::components::AffixFuzzer8>(Descriptor_fuzz1108)
                .value_or_throw();
        archetype.fuzz1109 =
            ComponentBatch::empty<rerun::components::AffixFuzzer9>(Descriptor_fuzz1109)
                .value_or_throw();
        archetype.fuzz1110 =
            ComponentBatch::empty<rerun::components::AffixFuzzer10>(Descriptor_fuzz1110)
                .value_or_throw();
        archetype.fuzz1111 =
            ComponentBatch::empty<rerun::components::AffixFuzzer11>(Descriptor_fuzz1111)
                .value_or_throw();
        archetype.fuzz1112 =
            ComponentBatch::empty<rerun::components::AffixFuzzer12>(Descriptor_fuzz1112)
                .value_or_throw();
        archetype.fuzz1113 =
            ComponentBatch::empty<rerun::components::AffixFuzzer13>(Descriptor_fuzz1113)
                .value_or_throw();
        archetype.fuzz1114 =
            ComponentBatch::empty<rerun::components::AffixFuzzer14>(Descriptor_fuzz1114)
                .value_or_throw();
        archetype.fuzz1115 =
            ComponentBatch::empty<rerun::components::AffixFuzzer15>(Descriptor_fuzz1115)
                .value_or_throw();
        archetype.fuzz1116 =
            ComponentBatch::empty<rerun::components::AffixFuzzer16>(Descriptor_fuzz1116)
                .value_or_throw();
        archetype.fuzz1117 =
            ComponentBatch::empty<rerun::components::AffixFuzzer17>(Descriptor_fuzz1117)
                .value_or_throw();
        archetype.fuzz1118 =
            ComponentBatch::empty<rerun::components::AffixFuzzer18>(Descriptor_fuzz1118)
                .value_or_throw();
        archetype.fuzz1122 =
            ComponentBatch::empty<rerun::components::AffixFuzzer22>(Descriptor_fuzz1122)
                .value_or_throw();
        return archetype;
    }

    Collection<ComponentColumn> AffixFuzzer2::columns(const Collection<uint32_t>& lengths_) {
        std::vector<ComponentColumn> columns;
        columns.reserve(19);
        if (fuzz1101.has_value()) {
            columns.push_back(fuzz1101.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1102.has_value()) {
            columns.push_back(fuzz1102.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1103.has_value()) {
            columns.push_back(fuzz1103.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1104.has_value()) {
            columns.push_back(fuzz1104.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1105.has_value()) {
            columns.push_back(fuzz1105.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1106.has_value()) {
            columns.push_back(fuzz1106.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1107.has_value()) {
            columns.push_back(fuzz1107.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1108.has_value()) {
            columns.push_back(fuzz1108.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1109.has_value()) {
            columns.push_back(fuzz1109.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1110.has_value()) {
            columns.push_back(fuzz1110.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1111.has_value()) {
            columns.push_back(fuzz1111.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1112.has_value()) {
            columns.push_back(fuzz1112.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1113.has_value()) {
            columns.push_back(fuzz1113.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1114.has_value()) {
            columns.push_back(fuzz1114.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1115.has_value()) {
            columns.push_back(fuzz1115.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1116.has_value()) {
            columns.push_back(fuzz1116.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1117.has_value()) {
            columns.push_back(fuzz1117.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1118.has_value()) {
            columns.push_back(fuzz1118.value().partitioned(lengths_).value_or_throw());
        }
        if (fuzz1122.has_value()) {
            columns.push_back(fuzz1122.value().partitioned(lengths_).value_or_throw());
        }
        return columns;
    }

    Collection<ComponentColumn> AffixFuzzer2::columns() {
        if (fuzz1101.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1101.value().length(), 1));
        }
        if (fuzz1102.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1102.value().length(), 1));
        }
        if (fuzz1103.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1103.value().length(), 1));
        }
        if (fuzz1104.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1104.value().length(), 1));
        }
        if (fuzz1105.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1105.value().length(), 1));
        }
        if (fuzz1106.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1106.value().length(), 1));
        }
        if (fuzz1107.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1107.value().length(), 1));
        }
        if (fuzz1108.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1108.value().length(), 1));
        }
        if (fuzz1109.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1109.value().length(), 1));
        }
        if (fuzz1110.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1110.value().length(), 1));
        }
        if (fuzz1111.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1111.value().length(), 1));
        }
        if (fuzz1112.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1112.value().length(), 1));
        }
        if (fuzz1113.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1113.value().length(), 1));
        }
        if (fuzz1114.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1114.value().length(), 1));
        }
        if (fuzz1115.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1115.value().length(), 1));
        }
        if (fuzz1116.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1116.value().length(), 1));
        }
        if (fuzz1117.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1117.value().length(), 1));
        }
        if (fuzz1118.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1118.value().length(), 1));
        }
        if (fuzz1122.has_value()) {
            return columns(std::vector<uint32_t>(fuzz1122.value().length(), 1));
        }
        return Collection<ComponentColumn>();
    }
} // namespace rerun::archetypes

namespace rerun {

    Result<Collection<ComponentBatch>> AsComponents<archetypes::AffixFuzzer2>::as_batches(
        const archetypes::AffixFuzzer2& archetype
    ) {
        using namespace archetypes;
        std::vector<ComponentBatch> cells;
        cells.reserve(19);

        if (archetype.fuzz1101.has_value()) {
            cells.push_back(archetype.fuzz1101.value());
        }
        if (archetype.fuzz1102.has_value()) {
            cells.push_back(archetype.fuzz1102.value());
        }
        if (archetype.fuzz1103.has_value()) {
            cells.push_back(archetype.fuzz1103.value());
        }
        if (archetype.fuzz1104.has_value()) {
            cells.push_back(archetype.fuzz1104.value());
        }
        if (archetype.fuzz1105.has_value()) {
            cells.push_back(archetype.fuzz1105.value());
        }
        if (archetype.fuzz1106.has_value()) {
            cells.push_back(archetype.fuzz1106.value());
        }
        if (archetype.fuzz1107.has_value()) {
            cells.push_back(archetype.fuzz1107.value());
        }
        if (archetype.fuzz1108.has_value()) {
            cells.push_back(archetype.fuzz1108.value());
        }
        if (archetype.fuzz1109.has_value()) {
            cells.push_back(archetype.fuzz1109.value());
        }
        if (archetype.fuzz1110.has_value()) {
            cells.push_back(archetype.fuzz1110.value());
        }
        if (archetype.fuzz1111.has_value()) {
            cells.push_back(archetype.fuzz1111.value());
        }
        if (archetype.fuzz1112.has_value()) {
            cells.push_back(archetype.fuzz1112.value());
        }
        if (archetype.fuzz1113.has_value()) {
            cells.push_back(archetype.fuzz1113.value());
        }
        if (archetype.fuzz1114.has_value()) {
            cells.push_back(archetype.fuzz1114.value());
        }
        if (archetype.fuzz1115.has_value()) {
            cells.push_back(archetype.fuzz1115.value());
        }
        if (archetype.fuzz1116.has_value()) {
            cells.push_back(archetype.fuzz1116.value());
        }
        if (archetype.fuzz1117.has_value()) {
            cells.push_back(archetype.fuzz1117.value());
        }
        if (archetype.fuzz1118.has_value()) {
            cells.push_back(archetype.fuzz1118.value());
        }
        if (archetype.fuzz1122.has_value()) {
            cells.push_back(archetype.fuzz1122.value());
        }

        return rerun::take_ownership(std::move(cells));
    }
} // namespace rerun
