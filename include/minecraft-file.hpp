#pragma once

/// @file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>
#if __has_include(<unistd.h>)
#include <unistd.h>
#endif
#if __has_include(<io.h>)
#include <io.h>
#endif
#if __has_include(<windows.h>)
#if !defined(NOMINMAX)
#define NOMINMAX
#endif
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

#include <algorithm>
#include <array>
#include <cassert>
#include <charconv>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <functional>
#include <initializer_list>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <ostream>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <inttypes.h>

#if __has_include(<leveldb/db.h>)
#include <leveldb/db.h>
#endif

#include <unicode/ucnv.h>
#include <unicode/ustring.h>

#include <libdeflate.h>
#include <lz4.h>
#include <xxhash.h>

// clang-format off

#include <mcfile/endianness.hpp>
#include <mcfile/encoding.hpp>
#include <mcfile/algorithm.hpp>
#include <mcfile/file.hpp>
#include <mcfile/scoped-file.hpp>
#include <mcfile/string.hpp>
#include <mcfile/stream/input-stream.hpp>
#include <mcfile/stream/output-stream.hpp>
#include <mcfile/stream/file-input-stream.hpp>
#include <mcfile/stream/file-output-stream.hpp>
#include <mcfile/stream/gz-file-output-stream.hpp>
#include <mcfile/stream/gz-file-input-stream.hpp>
#include <mcfile/stream/byte-stream.hpp>
#include <mcfile/stream/byte-input-stream.hpp>
#include <mcfile/stream/input-stream-reader.hpp>
#include <mcfile/stream/output-stream-writer.hpp>
#include <mcfile/stream/defer-opening-output-stream.hpp>
#include <mcfile/u8stream.hpp>
#include <mcfile/mem.hpp>
#include <mcfile/xxhash.hpp>
#include <mcfile/compression.hpp>
#include <mcfile/nbt/tag-factory.hpp>
#include <mcfile/nbt/tag.hpp>
#include <mcfile/nbt/end-tag.hpp>
#include <mcfile/nbt/detail/scalar-tag.hpp>
#include <mcfile/nbt/byte-tag.hpp>
#include <mcfile/nbt/short-tag.hpp>
#include <mcfile/nbt/int-tag.hpp>
#include <mcfile/nbt/long-tag.hpp>
#include <mcfile/nbt/float-tag.hpp>
#include <mcfile/nbt/double-tag.hpp>
#include <mcfile/nbt/detail/vector-tag.hpp>
#include <mcfile/nbt/byte-array-tag.hpp>
#include <mcfile/nbt/int-array-tag.hpp>
#include <mcfile/nbt/long-array-tag.hpp>
#include <mcfile/nbt/string-tag.hpp>
#include <mcfile/nbt/list-tag.hpp>
#include <mcfile/nbt/compound-tag.hpp>
#include <mcfile/nbt/tag-factory-impl.hpp>
#include <mcfile/pos2.hpp>
#include <mcfile/pos3.hpp>
#include <mcfile/coordinate.hpp>
#include <mcfile/blocks/block-id.hpp>
#include <mcfile/blocks/minecraft.hpp>
#include <mcfile/blocks/from-name.hpp>
#include <mcfile/blocks/name.hpp>
#include <mcfile/data4b3d.hpp>

#include <mcfile/je/block.hpp>
#include <mcfile/biomes/biome-id.hpp>
#include <mcfile/biomes/minecraft.hpp>
#include <mcfile/dimension.hpp>
#include <mcfile/biomes/biome.hpp>
#include <mcfile/palette-list.hpp>
#include <mcfile/je/block-palette.hpp>
#include <mcfile/biome-palette.hpp>
#include <mcfile/je/flatten.hpp>
#include <mcfile/je/chunk-section.hpp>
#include <mcfile/je/chunksection/chunk-section-112.hpp>
#include <mcfile/je/chunksection/chunk-section-113-base.hpp>
#include <mcfile/je/chunksection/block-states-parser-113.hpp>
#include <mcfile/je/chunksection/block-states-parser-116.hpp>
#include <mcfile/je/chunksection/chunk-section-113.hpp>
#include <mcfile/je/chunksection/chunk-section-116.hpp>
#include <mcfile/je/chunksection/chunk-section-118.hpp>
#include <mcfile/je/chunksection/chunk-section-empty.hpp>
#include <mcfile/je/chunksection/chunk-section-generator.hpp>
#include <mcfile/je/set-block-options.hpp>
#include <mcfile/je/ticking-block.hpp>
#include <mcfile/je/chunk.hpp>
#include <mcfile/je/heightmaps.hpp>
#include <mcfile/je/writable-chunk.hpp>
#include <mcfile/je/region-compression.hpp>
#include <mcfile/je/mca-chunk-locator.hpp>
#include <mcfile/je/region.hpp>
#include <mcfile/je/mca-editor.hpp>
#include <mcfile/je/world.hpp>

#include <mcfile/be/db-key.hpp>
#include <mcfile/be/db-interface.hpp>
#include <mcfile/be/db.hpp>
#include <mcfile/be/wrap-db.hpp>
#include <mcfile/be/block.hpp>
#include <mcfile/be/pending-tick.hpp>
#include <mcfile/be/sub-chunk.hpp>
#include <mcfile/be/biome.hpp>
#include <mcfile/be/biome-section.hpp>
#include <mcfile/be/biome-map.hpp>
#include <mcfile/be/chunk.hpp>

#include <mcfile/blocks/block-data.hpp>

#include <mcfile/blocks/data/bisected.hpp>
#include <mcfile/blocks/data/directional.hpp>
#include <mcfile/blocks/data/ageable.hpp>

#include <mcfile/blocks/data/type/stairs.hpp>
#include <mcfile/blocks/make-block-data.hpp>

#include <mcfile/nbt/print-as-json.hpp>
#include <mcfile/pos2.hpp>
#include <mcfile/je/cached-chunk-loader.hpp>
