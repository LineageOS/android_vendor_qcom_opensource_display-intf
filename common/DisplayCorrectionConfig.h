// Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
// SPDX-License-Identifier: BSD-3-Clause-Clear

#ifndef __COMMON_DISPLAYCORRECTIONCONFIG_H__
#define __COMMON_DISPLAYCORRECTIONCONFIG_H__

#include <string>
#include <set>
#include <memory>

#include "DistortionMesh.h"
/**
 * Display correction config.
 */

typedef struct vendor_qti_hardware_display_common_DisplayCorrectionConfig {

  // Handle all correction types
  struct DistortionConfig {
    inline static const char *name = "Distortion";
    bool enable;
    std::set<std::string> excluded_layer_keywords;
    std::string filepath_left, filepath_right;
    std::shared_ptr<vendor_qti_hardware_display_common_DistortionMesh> mesh;
  };

  struct V53SPRConfig {
    inline static const char *name = "V53SPR";
    bool enable;
    std::set<std::string> excluded_layer_keywords;
    int32_t flip_x;
    int32_t flip_y;
  };

  DistortionConfig distortion;
  V53SPRConfig v53spr;
  bool enable_gpu_timer = false;

  template <typename T>
  static bool CorrectionEnabledForLayer(const T &correction,
                                        std::string layer_name) {
    if (!correction.enable) {
      return false;
    }

    for (const auto &keyword : correction.excluded_layer_keywords) {
      if (layer_name.find(keyword) != std::string::npos) {
        return false;
      }
    }
    return true;
  }

  bool CorrectionsEnabled() const {
    // Handle all correction types (e.g. type1.enable || type2.enable || ...)
    return v53spr.enable || distortion.enable;
  }

} vendor_qti_hardware_display_common_DisplayCorrectionConfig;

#endif // __COMMON_DISPLAYCORRECTIONCONFIG_H__
