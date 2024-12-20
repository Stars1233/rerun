// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/testing/archetypes/fuzzy.fbs".

#include "affix_fuzzer4.hpp"

#include <rerun/collection_adapter_builtins.hpp>

namespace rerun::archetypes {}

namespace rerun {

    Result<std::vector<ComponentBatch>> AsComponents<archetypes::AffixFuzzer4>::serialize(
        const archetypes::AffixFuzzer4& archetype
    ) {
        using namespace archetypes;
        std::vector<ComponentBatch> cells;
        cells.reserve(19);

        if (archetype.fuzz2101.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2101.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2101",
                    "rerun.testing.components.AffixFuzzer1"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2102.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2102.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2102",
                    "rerun.testing.components.AffixFuzzer2"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2103.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2103.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2103",
                    "rerun.testing.components.AffixFuzzer3"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2104.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2104.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2104",
                    "rerun.testing.components.AffixFuzzer4"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2105.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2105.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2105",
                    "rerun.testing.components.AffixFuzzer5"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2106.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2106.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2106",
                    "rerun.testing.components.AffixFuzzer6"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2107.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2107.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2107",
                    "rerun.testing.components.AffixFuzzer7"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2108.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2108.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2108",
                    "rerun.testing.components.AffixFuzzer8"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2109.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2109.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2109",
                    "rerun.testing.components.AffixFuzzer9"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2110.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2110.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2110",
                    "rerun.testing.components.AffixFuzzer10"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2111.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2111.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2111",
                    "rerun.testing.components.AffixFuzzer11"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2112.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2112.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2112",
                    "rerun.testing.components.AffixFuzzer12"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2113.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2113.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2113",
                    "rerun.testing.components.AffixFuzzer13"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2114.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2114.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2114",
                    "rerun.testing.components.AffixFuzzer14"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2115.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2115.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2115",
                    "rerun.testing.components.AffixFuzzer15"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2116.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2116.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2116",
                    "rerun.testing.components.AffixFuzzer16"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2117.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2117.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2117",
                    "rerun.testing.components.AffixFuzzer17"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        if (archetype.fuzz2118.has_value()) {
            auto result = ComponentBatch::from_loggable(
                archetype.fuzz2118.value(),
                ComponentDescriptor(
                    "rerun.testing.archetypes.AffixFuzzer4",
                    "fuzz2118",
                    "rerun.testing.components.AffixFuzzer18"
                )
            );
            RR_RETURN_NOT_OK(result.error);
            cells.push_back(std::move(result.value));
        }
        {
            auto indicator = AffixFuzzer4::IndicatorComponent();
            auto result = ComponentBatch::from_loggable(indicator);
            RR_RETURN_NOT_OK(result.error);
            cells.emplace_back(std::move(result.value));
        }

        return cells;
    }
} // namespace rerun
