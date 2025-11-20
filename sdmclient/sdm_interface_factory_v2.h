/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#ifndef __SDM_INTERFACE_FACTORY_V2_H__
#define __SDM_INTERFACE_FACTORY_V2_H__

#include "sdm_interface_factory.h"
#include "sdm_display_intf_lifecycle_v2.h"

namespace sdm {

class SDMInterfaceFactoryV2 : public SDMInterfaceFactory {
public:
  virtual ~SDMInterfaceFactoryV2() {}

  virtual std::shared_ptr<SDMDisplayLifeCycleIntfV2> CreateLifeCycleIntfV2() = 0;
};

SDMInterfaceFactoryV2 *GetSDMInterfaceFactoryV2();

} // namespace sdm

#endif //  __SDM_INTERFACE_FACTORY_V2_H__
