/*
 * Copyright (c) 2014-2021, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Copyright 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Changes from Qualcomm Technologies, Inc. are provided under the following
 * license: Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#ifndef __SDM_DISPLAY_LAYER_BUILDER_INTF_H__
#define __SDM_DISPLAY_LAYER_BUILDER_INTF_H__

#include <unordered_map>
#include <unordered_set>

#include <SnapHandle.h>
#include <core/buffer_allocator.h>
#include <core/sdm_types.h>

namespace sdm {

using SnapHandle = vendor::qti::hardware::display::snapalloc::SnapHandle;

class SDMDisplayLayerBuilderIntf {
public:
  virtual ~SDMDisplayLayerBuilderIntf() {}

  virtual DisplayError Init(BufferAllocator *buffer_allocator,
                            uint64_t display_id) {
    return kErrorNone;
  };

  virtual DisplayError DeInit(uint64_t display_id) { return kErrorNone; };

  virtual DisplayError CreateLayer(uint64_t display_id, int64_t *out_layer_id) {
    return kErrorNone;
  };

  virtual DisplayError DestroyLayer(uint64_t display_id, int64_t layer_id) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerBuffer(uint64_t display_id, int64_t layer_id,
                                      const SnapHandle *buffer,
                                      const shared_ptr<Fence> &acquire_fence) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerBlendMode(uint64_t display_id, int64_t layer_id,
                                         int32_t int_mode) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerDisplayFrame(uint64_t display_id,
                                            int64_t layer_id, SDMRect frame) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerPlaneAlpha(uint64_t display_id, int64_t layer_id,
                                          float alpha) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerSourceCrop(uint64_t display_id, int64_t layer_id,
                                          SDMRect crop) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerTransform(uint64_t display_id, int64_t layer_id,
                                         SDMTransform transform) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerZOrder(uint64_t display_id, int64_t layer_id,
                                      uint32_t z) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerType(uint64_t display_id, int64_t layer_id,
                                    SDMLayerTypes type) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerFlag(uint64_t display_id, int64_t layer_id,
                                    SDMLayerFlag flag) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerSurfaceDamage(uint64_t display_id,
                                             int64_t layer_id,
                                             SDMRegion damage) {
    return kErrorNone;
  };
  virtual DisplayError SetLayerVisibleRegion(uint64_t display_id,
                                             int64_t layer_id,
                                             SDMRegion damage) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerCompositionType(uint64_t display_id,
                                               int64_t layer_id,
                                               int32_t int_type) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerColor(uint64_t display_id, int64_t layer_id,
                                     SDMColor color) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerDataspace(uint64_t display_id, int64_t layer_id,
                                         int32_t dataspace) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerPerFrameMetadata(uint64_t display_id,
                                                int64_t layer_id,
                                                uint32_t num_elements,
                                                const int32_t *int_keys,
                                                const float *metadata) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerColorTransform(uint64_t display_id,
                                              int64_t layer_id,
                                              const float *matrix) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerPerFrameMetadataBlobs(
      uint64_t display_id, int64_t layer_id, uint32_t num_elements,
      const int32_t *int_keys, const uint32_t *sizes, const uint8_t *metadata) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerBrightness(uint64_t display_id, int64_t layer_id,
                                          float brightness) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerAsMask(uint64_t display_id, int64_t layer_id) {
    return kErrorNone;
  };

  virtual SDMCompositionType
  GetDeviceSelectedCompositionType(uint64_t display_id, int64_t layer_id) {
    return COMP_INVALID;
  };

  virtual DisplayError SetCursorPosition(uint64_t disp_id, int64_t layer_id,
                                         int32_t x, int32_t y) {
    return kErrorNone;
  };

  virtual LayerBufferFormat GetSDMFormat(const int32_t &source,
                                         const int32_t flags,
                                         const int64_t compression_type) {
    return kFormatInvalid;
  };
  virtual bool CheckLayerBufferBinding(uint64_t display_id, int64_t layer_id,
                                       const SnapHandle *buffer) {
    return false;
  };

  virtual DisplayError
  SetLayerPrivacyRegions(uint64_t display_id, int64_t layer_id,
                         const std::vector<PrivacyRegion> &privacy_regions) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerCornerRadius(uint64_t display_id,
                                            int64_t layer_id,
                                            CornerRadius corner_radius) {
    return kErrorNone;
  };

#ifdef LSR_API
  virtual DisplayError SetRenderLayerReferenceSpaceType(
      uint64_t display, int64_t layer,
      SDMRenderLayerReferenceSpaceType reference_layer_space_type) {
    return kErrorNone;
  };

  virtual DisplayError
  SetCompositionLayerType(uint64_t display, int64_t layer,
                          SDMCompositionLayerType comp_layer_type) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerPose(uint64_t display, int64_t layer,
                                    SDMLayerPose layer_pose) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerQuadSize(uint64_t display, int64_t layer,
                                        SDMLayerQuadSize layer_quad_size) {
    return kErrorNone;
  };

  virtual DisplayError SetLayerFrustum(uint64_t display, int64_t layer,
                                       SDMLayerFrustum layer_frustum) {
    return kErrorNone;
  };

  virtual DisplayError
  SetLayerPlaneEquation(uint64_t display, int64_t layer,
                        SDMLayerPlaneEquation plane_equation) {
    return kErrorNone;
  };

  virtual DisplayError
  SetLayerVisibilityType(uint64_t display, int64_t layer,
                         SDMLayerVisibilityType layer_visibility_type) {
    return kErrorNone;
  };
#endif
};

} // namespace sdm

#endif // __SDM_DISPLAY_LAYER_BUILDER_INTF_H__
