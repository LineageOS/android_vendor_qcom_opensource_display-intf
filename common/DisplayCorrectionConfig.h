// Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
// SPDX-License-Identifier: BSD-3-Clause-Clear

#ifndef __COMMON_DISPLAYCORRECTIONCONFIG_H__
#define __COMMON_DISPLAYCORRECTIONCONFIG_H__

#include <string>
/**
 * Display correction config.
 */

typedef struct vendor_qti_hardware_display_common_DisplayCorrectionConfig {
  vendor_qti_hardware_display_common_DisplayCorrectionConfig &operator=(
      const vendor_qti_hardware_display_common_DisplayCorrectionConfig &) =
      default;

  // Handle all correction types
  struct V53SPRConfig {
    inline static const char *name = "V53SPR";
    bool enable;
    std::vector<std::string> excluded_layer_keywords;
    int32_t flip_x;
    int32_t flip_y;
  };
  V53SPRConfig v53spr;

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
    return v53spr.enable;
  }

  void DebugPrint() const;
} vendor_qti_hardware_display_common_DisplayCorrectionConfig;

#endif // __COMMON_DISPLAYCORRECTIONCONFIG_H__
