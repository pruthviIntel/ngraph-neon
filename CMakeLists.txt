# ******************************************************************************
# Copyright 2017-2018 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ******************************************************************************

cmake_minimum_required (VERSION 3.1)

# Suppress an OS X-specific warning.
if (POLICY CMP0042)
    cmake_policy(SET CMP0042 OLD)
endif()

project (neon)

include(ExternalProject)

ExternalProject_Add(
    aeon
    GIT_REPOSITORY "https://github.com/NervanaSystems/aeon.git"
    GIT_TAG "v1.3.1"
    LOG_CONFIGURE 1
    BUILD_COMMAND ""
    LOG INSTALL 1
    INSTALL_COMMAND pip install -U .
    )


set(NGRAPH_CMAKE_ARGS "")

if(DEFINED NGRAPH_GPU_ENABLE)
    set(NGRAPH_CMAKE_ARGS "-DNGRAPH_GPU_ENABLE=TRUE" ${NGRAPH_CMAKE_ARGS})
endif()
if(DEFINED NGRAPH_USE_PREBUILT_LLVM)
    set(NGRAPH_CMAKE_ARGS "-DNGRAPH_USE_PREBUILT_LLVM=TRUE" ${NGRAPH_CMAKE_ARGS})
endif()

set(MAKE_PARALLEL_ARGS "-j")

if(DEFINED NUM_THREADS)
    set(MAKE_PARALLEL_ARGS ${MAKE_PARALLEL_ARGS} ${NUM_THREADS})
else()
    set(MAKE_PARALLEL_ARGS ${MAKE_PARALLEL_ARGS} "8")
endif()

ExternalProject_Add(
    pyngraph
    GIT_REPOSITORY "https://github.com/NervanaSystems/ngraph.git"
    GIT_TAG "silee2/neon_cmake"
    CONFIGURE_COMMAND cmake ${NGRAPH_CMAKE_ARGS} ../pyngraph/python
    LOG_CONFIGURE 1
    BUILD_COMMAND make ${MAKE_PARALLEL_ARGS}
    LOG_BUILD 1
    LOG INSTALL 1
    INSTALL_COMMAND pip install -U .
    )

