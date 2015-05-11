#pragma once

namespace hesaff {

struct Keypoint
{
    float x, y, s;

    // size of the measurement region (as multiple of the feature scale)
    float mrSize;

    float a11,a12,a21,a22;
    float response;
    int type;                // HessianDetector enum: HESSIAN_DARK, HESSIAN_BRIGHT, HESSIAN_SADDLE
    unsigned char desc[128]; // SIFT descriptor
};

// Detects Hessian Affine points and describes them using SIFT descriptor
// The detector assumes that the vertical orientation is preserved.
std::vector<Keypoint> hessian_affine(cv::Mat const &src);

}   // namespace hesaff
