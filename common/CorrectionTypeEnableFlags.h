// Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
// SPDX-License-Identifier: BSD-3-Clause-Clear

#ifndef __COMMON_CORRECTIONTYPEENABLEFLAGS_H__
#define __COMMON_CORRECTIONTYPEENABLEFLAGS_H__

#include <string>
/**
 * Correction type enable flags
 */

typedef struct vendor_qti_hardware_display_common_CorrectionTypeEnableFlags {
  bool v53spr;

  inline bool
  operator==(const vendor_qti_hardware_display_common_CorrectionTypeEnableFlags
                 other) {
    return this->v53spr == other.v53spr;
  }
  inline bool
  operator!=(const vendor_qti_hardware_display_common_CorrectionTypeEnableFlags
                 &other) {
    return !(*this == other);
  }

  operator bool() { return this->v53spr; }
} vendor_qti_hardware_display_common_CorrectionTypeEnableFlags;

#endif // __COMMON_CORRECTIONTYPEENABLEFLAGS_H__
