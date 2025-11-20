/*
 * Copyright (c) 2025 Qualcomm Innovation Center, Inc. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#ifndef __SDM_DISPLAY_INTF_DRAWCYCLE_V2_H__
#define __SDM_DISPLAY_INTF_DRAWCYCLE_V2_H__

#include "sdm_display_intf_drawcycle.h"

namespace sdm {

class SDMDisplayDrawCycleIntfV2 : public SDMDisplayDrawCycleIntf {
public:
  using SDMDisplayDrawCycleIntf::SetClientTarget;
  virtual ~SDMDisplayDrawCycleIntfV2() {}

  virtual DisplayError
  SetClientTarget(uint64_t display, const SnapHandle *target,
                  shared_ptr<Fence> acquire_fence, int32_t dataspace,
                  const SDMRegion &damage, uint32_t version,
                  float hdr_sdr_ratio) = 0;
  virtual DisplayError GetDisplayLuts(
      uint64_t display,
      std::unique_ptr<std::vector<std::pair<LayerId, Lut3d *>>> &out_luts) = 0;
  virtual DisplayError
  GetBufferLuts(uint64_t display, const std::vector<SnapHandle *> &buffers,
                std::unique_ptr<std::vector<Lut3d *>> &out_luts) = 0;
};

} // namespace sdm

#endif // __SDM_DISPLAY_INTF_DRAWCYCLE_V2_H__
