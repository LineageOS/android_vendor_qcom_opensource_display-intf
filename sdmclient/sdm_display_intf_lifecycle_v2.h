/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#ifndef __SDM_DISPLAY_INTF_LIFECYCLE_V2_H__
#define __SDM_DISPLAY_INTF_LIFECYCLE_V2_H__

#include "sdm_compositor_sideband_cb_intf_v2.h"
#include "sdm_display_intf_lifecycle.h"

namespace sdm {

class SDMDisplayLifeCycleIntfV2 : public SDMDisplayLifeCycleIntf {
public:
  virtual ~SDMDisplayLifeCycleIntfV2() {}

  virtual void RegisterSideBandV2Callback(SDMSideBandCompositorCbIntfV2 *cb,
                                          bool enable) = 0;
};

} //  namespace sdm

#endif //  __SDM_DISPLAY_INTF_LIFECYCLE_V2_H__
