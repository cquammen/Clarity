#ifndef __ComplexCUDA_H_
#define __ComplexCUDA_H_

#include <cufft.h>

/** Complex type, a two-element array of floats. */
typedef float2 Complex;


/**
 * Returns conjugate of a complex number.
 * 
 * @param c Complex number to conjugate.
 * @return Conjugate of c1.
 */
__device__ Complex ComplexConjugate(Complex c) {
   Complex t;
   t.x =  c.x;
   t.y = -c.y;
   return t;
}


/**
 * Adds two complex numbers.
 * 
 * @param c1 First complex number.
 * @param c2 Second complex number.
 * @return Complex result of the addition.
 */
__device__ Complex ComplexAdd(Complex c1, Complex c2) {
    Complex t;
    t.x = c1.x + c2.x;
    t.y = c1.y + c2.y;
    return t;
}


/**
 * Multiplies two complex numbers.
 * 
 * @param c1 First complex number.
 * @param c2 Second complex number.
 * @return Complex result of the multiplication.
 */
__device__ Complex ComplexMultiply(Complex c1, Complex c2) {
    Complex t;
    t.x = c1.x * c2.x - c1.y * c2.y;
    t.y = c1.x * c2.y + c1.y * c2.x;
    return t;
}


/**
 * Scales a complex number by a real value.
 * 
 * @param c Complex number to scale.
 * @param s Real scale value.
 * @return Complex result of scaling operation.
 */
__device__ Complex ComplexScale(Complex c, float s) {
    Complex t;
    t.x = c.x * s;
    t.y = c.y * s;
    return t;
}


/**
 * Multiplies two complex numbers and scales the result by a real number.
 * 
 * @param c1 First complex number.
 * @param c2 Second complex number.
 * @param s  Real scale value.
 * @return Complex result of the operation.
 */
__device__ Complex ComplexMultiplyAndScale(Complex c1, Complex c2, float s) {
    return ComplexScale(ComplexMultiply(c1, c2), s);
}


/**
 * Computes squared magnitude of a complex number, returning real result.
 * 
 * @param c Complex number whose magnitude should be taken.
 * @return Squared magnitude.
 */
__device__ float ComplexMagnitudeSquared(Complex c) {
   return ((c.x*c.x) + (c.y*c.y));
}

#endif // __ComplexCUDA_H_
