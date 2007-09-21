#include "Clarity.h"

ClarityResult_t
Clarity_SmoothedJansenVanCittertDeconvolve(float* outImage, float* inImage, float* psfImage,
                                           int nx, int ny, int nz, unsigned iterations, 
                                           unsigned smoothInterval, float smoothSigma[3]) {

   // Temporary code to produce something for checking whether VTK hookup works.
   int size = nx * ny * nz;
   for (int i = 0; i < size; i++) {
      outImage[i] = 0.0f;
   }

   return CLARITY_SUCCESS;
}
