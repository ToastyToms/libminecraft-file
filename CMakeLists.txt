cmake_minimum_required(VERSION 3.8)
project(mcfile)

include(CheckCCompilerFlag)
include(cmake/CPM.cmake)

if ("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  set(BUILD_SHARED_LIBS OFF)

  if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
  endif()
  if (MSVC)
    add_compile_options(
      /utf-8
      /MP
      /ZI
      /Zc:__cplusplus # Enable updated __cplusplus macro
      /Zc:preprocessor # Enable preprocessor conformance mode
    )
  endif()
endif()

set(mcfile_files
  # git ls-files | grep 'hpp$' | grep -v '^test' | pbcopy
  #begin libminecraft-file source files
  include/mcfile/algorithm.hpp
  include/mcfile/be/biome-map.hpp
  include/mcfile/be/biome-section.hpp
  include/mcfile/be/biome.hpp
  include/mcfile/be/block.hpp
  include/mcfile/be/chunk.hpp
  include/mcfile/be/db-interface.hpp
  include/mcfile/be/db-key.hpp
  include/mcfile/be/db.hpp
  include/mcfile/be/pending-tick.hpp
  include/mcfile/be/sub-chunk.hpp
  include/mcfile/be/wrap-db.hpp
  include/mcfile/biome-palette.hpp
  include/mcfile/biomes/biome-id.hpp
  include/mcfile/biomes/biome.hpp
  include/mcfile/biomes/minecraft.hpp
  include/mcfile/blocks/block-data.hpp
  include/mcfile/blocks/block-id.hpp
  include/mcfile/blocks/data/ageable.hpp
  include/mcfile/blocks/data/bisected.hpp
  include/mcfile/blocks/data/directional.hpp
  include/mcfile/blocks/data/type/stairs.hpp
  include/mcfile/blocks/from-name.hpp
  include/mcfile/blocks/make-block-data.hpp
  include/mcfile/blocks/minecraft.hpp
  include/mcfile/blocks/name.hpp
  include/mcfile/compression.hpp
  include/mcfile/coordinate.hpp
  include/mcfile/data4b3d.hpp
  include/mcfile/dimension.hpp
  include/mcfile/encoding.hpp
  include/mcfile/endianness.hpp
  include/mcfile/file.hpp
  include/mcfile/je/block-palette.hpp
  include/mcfile/je/block.hpp
  include/mcfile/je/cached-chunk-loader.hpp
  include/mcfile/je/chunk-section.hpp
  include/mcfile/je/chunk.hpp
  include/mcfile/je/chunksection/block-states-parser-113.hpp
  include/mcfile/je/chunksection/block-states-parser-116.hpp
  include/mcfile/je/chunksection/chunk-section-112.hpp
  include/mcfile/je/chunksection/chunk-section-113-base.hpp
  include/mcfile/je/chunksection/chunk-section-113.hpp
  include/mcfile/je/chunksection/chunk-section-116.hpp
  include/mcfile/je/chunksection/chunk-section-118.hpp
  include/mcfile/je/chunksection/chunk-section-empty.hpp
  include/mcfile/je/chunksection/chunk-section-generator.hpp
  include/mcfile/je/flatten.hpp
  include/mcfile/je/heightmaps.hpp
  include/mcfile/je/mca-chunk-locator.hpp
  include/mcfile/je/mca-editor.hpp
  include/mcfile/je/region-compression.hpp
  include/mcfile/je/region.hpp
  include/mcfile/je/set-block-options.hpp
  include/mcfile/je/ticking-block.hpp
  include/mcfile/je/world.hpp
  include/mcfile/je/writable-chunk.hpp
  include/mcfile/mem.hpp
  include/mcfile/nbt/byte-array-tag.hpp
  include/mcfile/nbt/byte-tag.hpp
  include/mcfile/nbt/compound-tag.hpp
  include/mcfile/nbt/detail/scalar-tag.hpp
  include/mcfile/nbt/detail/vector-tag.hpp
  include/mcfile/nbt/double-tag.hpp
  include/mcfile/nbt/end-tag.hpp
  include/mcfile/nbt/float-tag.hpp
  include/mcfile/nbt/int-array-tag.hpp
  include/mcfile/nbt/int-tag.hpp
  include/mcfile/nbt/list-tag.hpp
  include/mcfile/nbt/long-array-tag.hpp
  include/mcfile/nbt/long-tag.hpp
  include/mcfile/nbt/print-as-json.hpp
  include/mcfile/nbt/short-tag.hpp
  include/mcfile/nbt/string-tag.hpp
  include/mcfile/nbt/tag-factory-impl.hpp
  include/mcfile/nbt/tag-factory.hpp
  include/mcfile/nbt/tag.hpp
  include/mcfile/palette-list.hpp
  include/mcfile/pos2.hpp
  include/mcfile/pos3.hpp
  include/mcfile/scoped-file.hpp
  include/mcfile/stream/byte-input-stream.hpp
  include/mcfile/stream/byte-stream.hpp
  include/mcfile/stream/defer-opening-output-stream.hpp
  include/mcfile/stream/file-input-stream.hpp
  include/mcfile/stream/file-output-stream.hpp
  include/mcfile/stream/gz-file-input-stream.hpp
  include/mcfile/stream/gz-file-output-stream.hpp
  include/mcfile/stream/input-stream-reader.hpp
  include/mcfile/stream/input-stream.hpp
  include/mcfile/stream/output-stream-writer.hpp
  include/mcfile/stream/output-stream.hpp
  include/mcfile/string.hpp
  include/mcfile/u8stream.hpp
  include/mcfile/xxhash.hpp
  include/minecraft-file.hpp
  #end libminecraft-file source files
  )
set(mcfile_test_files
  test/main.cpp
  test/be/biome-section.test.cpp
  test/be/biome.test.cpp
  test/be/db-key.test.cpp
  test/Point3D.hpp
  test/BlockData.hpp
  test/flatten.test.cpp
  test/nbt.test.cpp
  test/data4b3d.test.cpp
  test/heightmap.test.cpp
  test/string.test.hpp
  test/biome.test.cpp
  test/snbt.test.cpp)

set(CMAKE_REQUIRED_FLAGS "-lstdc++fs")
check_c_compiler_flag("" TEST_RESULT_STDCXXFS)
if (TEST_RESULT_STDCXXFS AND "${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  list(APPEND mcfile_test_link_libraries stdc++fs)
endif()

find_package(ZLIB QUIET)
if (ZLIB_FOUND)
  list(APPEND mcfile_test_link_libraries ZLIB::ZLIB)
else()
  CPMAddPackage(
    NAME ZLIB
    GITHUB_REPOSITORY madler/zlib
    GIT_TAG v1.3)
  target_include_directories(zlibstatic INTERFACE ${ZLIB_SOURCE_DIR} $<TARGET_PROPERTY:zlibstatic,BINARY_DIR>)
  list(APPEND mcfile_test_link_libraries zlibstatic)
endif()

CPMAddPackage("gh:ebiggers/libdeflate@1.20")
list(APPEND mcfile_test_link_libraries libdeflate::libdeflate_static)

CPMAddPackage(
  NAME lz4
  GITHUB_REPOSITORY lz4/lz4
  GIT_TAG v1.9.4
  DOWNLOAD_ONLY YES)
add_subdirectory(${lz4_SOURCE_DIR}/build/cmake ${lz4_SOURCE_DIR} EXCLUDE_FROM_ALL)
list(APPEND mcfile_test_link_libraries lz4_static)

CPMAddPackage("gh:doctest/doctest@2.4.11")

include(cmake/icu-cpm.cmake)
list(APPEND mcfile_test_link_libraries icu::uc)

add_library(mcfile INTERFACE ${mcfile_files})
target_include_directories(mcfile INTERFACE include)
target_link_libraries(mcfile INTERFACE ${mcfile_test_link_libraries})

add_executable(mcfile-test ${mcfile_test_files})
target_link_libraries(mcfile-test mcfile doctest)
if (MSVC)
  target_compile_options(mcfile-test PRIVATE /bigobj)
endif()

add_executable(mcfile-example example/main.cpp)
target_link_libraries(mcfile-example mcfile)

source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${mcfile_test_files})
