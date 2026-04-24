// Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
// SPDX-License-Identifier: BSD-3-Clause-Clear

#ifndef __COMMON_DISTORTIONMESH_H__
#define __COMMON_DISTORTIONMESH_H__

#include <cstddef>
#include <cstdint>
#include <vector>

typedef struct vendor_qti_hardware_display_common_DistortionMesh {

  static std::shared_ptr<vendor_qti_hardware_display_common_DistortionMesh>
  Merge(const vendor_qti_hardware_display_common_DistortionMesh &left,
        const vendor_qti_hardware_display_common_DistortionMesh &right,
        const uint16_t primitive_restart_index = kPrimitiveRestartIndex) {
    vendor_qti_hardware_display_common_DistortionMesh combined = {};
    // Transform functions for left ,right and middle parts
    auto noop = [](auto &dummy) {};
    auto pos_left = [](auto &p) {
      p.x = (p.x - 1.0f) * 0.5f;
    }; // [-1,1] -> [-1,0]
    auto pos_right = [](auto &p) {
      p.x = (p.x + 1.0f) * 0.5f;
    }; // [-1,1] -> [ 0,1]
    auto uv_left = [](auto &uv) {
      uv.u = uv.u * 0.5;
    }; // [0,1] -> [0, 0.5]
    auto uv_right = [](auto &uv) {
      uv.u = 0.5 + uv.u * 0.5;
    }; // [0,1] -> [0.5, 1]
    auto idx_right = [&](auto &idx) {
      idx += left.pos.size();
    }; // add counts of left vertices
    auto idx_mid = [&](auto &left) {
      left.push_back(primitive_restart_index); // insert primitive_restart idx
    };

    /** This lambda function takes two input containers (`left` and `right`),
     * transforms their elements using provided operations, and merges the
     * results into a combined container (i.e. the distortion mesh)
     * (`combined`).
     *
     * Parameters:
     *   - `left`: The left-side input container.
     *   - `right`: The right-side input container.
     *   - `combined`: The output container where merged results are stored.
     *   - `op_left`: A lambda function that modifies elements from the `left`
     * container before adding them to `combined`.
     *   - `op_right`: A lambda function that modifies elements from the `right`
     * container before adding them to `combined`.
     *   - `op_mid`: A lambda function that is called after processing all
     * elements from the `left` container, and before processing the `right`
     * container. This function is used to add a separator or perform other
     * operations between the merged parts.
     */
    auto transform_and_merge = [](auto &&left, auto &&right, auto &combined,
                                  auto &&op_left, auto &&op_right,
                                  auto &&op_mid) {
      for (auto v : left) {
        op_left(v);
        combined.push_back(v);
      }
      op_mid(combined);
      for (auto v : right) {
        op_right(v);
        combined.push_back(v);
      }
    };

    transform_and_merge(left.pos, right.pos, combined.pos, pos_left, pos_right,
                        noop);
    transform_and_merge(left.tex_r, right.tex_r, combined.tex_r, uv_left,
                        uv_right, noop);
    transform_and_merge(left.tex_g, right.tex_g, combined.tex_g, uv_left,
                        uv_right, noop);
    transform_and_merge(left.tex_b, right.tex_b, combined.tex_b, uv_left,
                        uv_right, noop);
    transform_and_merge(left.indices, right.indices, combined.indices, noop,
                        idx_right, idx_mid);

    return std::make_shared<vendor_qti_hardware_display_common_DistortionMesh>(
        std::move(combined));
  }

  struct XY {
    union {
      float x, u;
    };
    union {
      float y, v;
    };
  };

  std::vector<XY> pos;
  std::vector<XY> tex_r;
  std::vector<XY> tex_g;
  std::vector<XY> tex_b;
  std::vector<uint16_t> indices;

  static const size_t kVertexSize = 4 * sizeof(XY);
  static const size_t kVertexCountSize = sizeof(int32_t);
  static const size_t kIndexSize = sizeof(uint16_t);
  static const size_t kIndexCountSize = sizeof(int32_t);
  // Custom Restart Index requires GLES 3.2+, the default restart index is
  // 0xFFFF
  static constexpr uint16_t kPrimitiveRestartIndex = 0xFFFF;

} vendor_qti_hardware_display_common_DistortionMesh;

#endif // __COMMON_DISTORTIONMESH_H__
