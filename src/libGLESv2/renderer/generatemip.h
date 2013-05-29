//
// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// generatemip.h: Defines the GenerateMip function, templated on the format
// type of the image for which mip levels are being generated.

#ifndef LIBGLESV2_RENDERER_GENERATEMIP_H_
#define LIBGLESV2_RENDERER_GENERATEMIP_H_

#include "common/mathutil.h"

namespace rx
{
struct L8
{
    unsigned char L;

    static void average(L8 *dst, const L8 *src1, const L8 *src2)
    {
        dst->L = ((src1->L ^ src2->L) >> 1) + (src1->L & src2->L);
    }
};

typedef L8 R8; // R8 type is functionally equivalent for mip purposes
typedef L8 A8; // A8 type is functionally equivalent for mip purposes

struct A8L8
{
    unsigned char L;
    unsigned char A;

    static void average(A8L8 *dst, const A8L8 *src1, const A8L8 *src2)
    {
        *(unsigned short*)dst = (((*(unsigned short*)src1 ^ *(unsigned short*)src2) & 0xFEFE) >> 1) + (*(unsigned short*)src1 & *(unsigned short*)src2);
    }
};

typedef A8L8 R8G8; // R8G8 type is functionally equivalent for mip purposes

struct A8R8G8B8
{
    unsigned char B;
    unsigned char G;
    unsigned char R;
    unsigned char A;

    static void average(A8R8G8B8 *dst, const A8R8G8B8 *src1, const A8R8G8B8 *src2)
    {
        *(unsigned int*)dst = (((*(unsigned int*)src1 ^ *(unsigned int*)src2) & 0xFEFEFEFE) >> 1) + (*(unsigned int*)src1 & *(unsigned int*)src2);
    }
};

typedef A8R8G8B8 R8G8B8A8; // R8G8B8A8 type is functionally equivalent for mip purposes
typedef A8R8G8B8 B8G8R8A8; // B8G8R8A8 type is functionally equivalent for mip purposes

struct R16
{
    unsigned short R;

    static void average(R16 *dst, const R16 *src1, const R16 *src2)
    {
        dst->R = ((src1->R ^ src2->R) >> 1) + (src1->R & src2->R);
    }
};

struct R16G16
{
    unsigned short R;
    unsigned short G;

    static void average(R16G16 *dst, const R16G16 *src1, const R16G16 *src2)
    {
        dst->R = ((src1->R ^ src2->R) >> 1) + (src1->R & src2->R);
        dst->G = ((src1->G ^ src2->G) >> 1) + (src1->G & src2->G);
    }
};

struct R16G16B16A16
{
    unsigned short R;
    unsigned short G;
    unsigned short B;
    unsigned short A;

    static void average(R16G16B16A16 *dst, const R16G16B16A16 *src1, const R16G16B16A16 *src2)
    {
        dst->R = ((src1->R ^ src2->R) >> 1) + (src1->R & src2->R);
        dst->G = ((src1->G ^ src2->G) >> 1) + (src1->G & src2->G);
        dst->B = ((src1->B ^ src2->B) >> 1) + (src1->B & src2->B);
        dst->A = ((src1->A ^ src2->A) >> 1) + (src1->A & src2->A);
    }
};

struct R32
{
    unsigned int R;

    static void average(R32 *dst, const R32 *src1, const R32 *src2)
    {
        dst->R = ((src1->R ^ src2->R) >> 1) + (src1->R & src2->R);
    }
};

struct R32G32
{
    unsigned int R;
    unsigned int G;

    static void average(R32G32 *dst, const R32G32 *src1, const R32G32 *src2)
    {
        dst->R = ((src1->R ^ src2->R) >> 1) + (src1->R & src2->R);
        dst->G = ((src1->G ^ src2->G) >> 1) + (src1->G & src2->G);
    }
};

struct R32G32B32
{
    unsigned int R;
    unsigned int G;
    unsigned int B;

    static void average(R32G32B32 *dst, const R32G32B32 *src1, const R32G32B32 *src2)
    {
        dst->R = ((src1->R ^ src2->R) >> 1) + (src1->R & src2->R);
        dst->G = ((src1->G ^ src2->G) >> 1) + (src1->G & src2->G);
        dst->B = ((src1->B ^ src2->B) >> 1) + (src1->B & src2->B);
    }
};

struct R32G32B32A32
{
    unsigned int R;
    unsigned int G;
    unsigned int B;
    unsigned int A;

    static void average(R32G32B32A32 *dst, const R32G32B32A32 *src1, const R32G32B32A32 *src2)
    {
        dst->R = ((src1->R ^ src2->R) >> 1) + (src1->R & src2->R);
        dst->G = ((src1->G ^ src2->G) >> 1) + (src1->G & src2->G);
        dst->B = ((src1->B ^ src2->B) >> 1) + (src1->B & src2->B);
        dst->A = ((src1->A ^ src2->A) >> 1) + (src1->A & src2->A);
    }
};

struct R8S
{
    char R;

    static void average(R8S *dst, const R8S *src1, const R8S *src2)
    {
        dst->R = ((short)src1->R + (short)src2->R) / 2;
    }
};

struct R8G8S
{
    char R;
    char G;

    static void average(R8G8S *dst, const R8G8S *src1, const R8G8S *src2)
    {
        dst->R = ((short)src1->R + (short)src2->R) / 2;
        dst->G = ((short)src1->G + (short)src2->G) / 2;
    }
};

struct R8G8B8A8S
{
    char R;
    char G;
    char B;
    char A;

    static void average(R8G8B8A8S *dst, const R8G8B8A8S *src1, const R8G8B8A8S *src2)
    {
        dst->R = ((short)src1->R + (short)src2->R) / 2;
        dst->G = ((short)src1->G + (short)src2->G) / 2;
        dst->B = ((short)src1->B + (short)src2->B) / 2;
        dst->A = ((short)src1->A + (short)src2->A) / 2;
    }
};

struct R16S
{
    unsigned short R;

    static void average(R16S *dst, const R16S *src1, const R16S *src2)
    {
        dst->R = ((int)src1->R + (int)src2->R) / 2;
    }
};

struct R16G16S
{
    unsigned short R;
    unsigned short G;

    static void average(R16G16S *dst, const R16G16S *src1, const R16G16S *src2)
    {
        dst->R = ((int)src1->R + (int)src2->R) / 2;
        dst->G = ((int)src1->G + (int)src2->G) / 2;
    }
};

struct R16G16B16A16S
{
    unsigned short R;
    unsigned short G;
    unsigned short B;
    unsigned short A;

    static void average(R16G16B16A16S *dst, const R16G16B16A16S *src1, const R16G16B16A16S *src2)
    {
        dst->R = ((int)src1->R + (int)src2->R) / 2;
        dst->G = ((int)src1->G + (int)src2->G) / 2;
        dst->B = ((int)src1->B + (int)src2->B) / 2;
        dst->A = ((int)src1->A + (int)src2->A) / 2;
    }
};

struct R32S
{
    unsigned int R;

    static void average(R32S *dst, const R32S *src1, const R32S *src2)
    {
        dst->R = ((long long)src1->R + (long long)src2->R) / 2;
    }
};

struct R32G32S
{
    unsigned int R;
    unsigned int G;

    static void average(R32G32S *dst, const R32G32S *src1, const R32G32S *src2)
    {
        dst->R = ((long long)src1->R + (long long)src2->R) / 2;
        dst->G = ((long long)src1->G + (long long)src2->G) / 2;
    }
};

struct R32G32B32S
{
    unsigned int R;
    unsigned int G;
    unsigned int B;

    static void average(R32G32B32S *dst, const R32G32B32S *src1, const R32G32B32S *src2)
    {
        dst->R = ((long long)src1->R + (long long)src2->R) / 2;
        dst->G = ((long long)src1->G + (long long)src2->G) / 2;
        dst->B = ((long long)src1->B + (long long)src2->B) / 2;
    }
};

struct R32G32B32A32S
{
    unsigned int R;
    unsigned int G;
    unsigned int B;
    unsigned int A;

    static void average(R32G32B32A32S *dst, const R32G32B32A32S *src1, const R32G32B32A32S *src2)
    {
        dst->R = ((long long)src1->R + (long long)src2->R) / 2;
        dst->G = ((long long)src1->G + (long long)src2->G) / 2;
        dst->B = ((long long)src1->B + (long long)src2->B) / 2;
        dst->A = ((long long)src1->A + (long long)src2->A) / 2;
    }
};

struct A16B16G16R16F
{
    unsigned short R;
    unsigned short G;
    unsigned short B;
    unsigned short A;

    static void average(A16B16G16R16F *dst, const A16B16G16R16F *src1, const A16B16G16R16F *src2)
    {
        dst->R = gl::float32ToFloat16((gl::float16ToFloat32(src1->R) + gl::float16ToFloat32(src2->R)) * 0.5f);
        dst->G = gl::float32ToFloat16((gl::float16ToFloat32(src1->G) + gl::float16ToFloat32(src2->G)) * 0.5f);
        dst->B = gl::float32ToFloat16((gl::float16ToFloat32(src1->B) + gl::float16ToFloat32(src2->B)) * 0.5f);
        dst->A = gl::float32ToFloat16((gl::float16ToFloat32(src1->A) + gl::float16ToFloat32(src2->A)) * 0.5f);
    }
};

struct R16F
{
    unsigned short R;

    static void average(R16F *dst, const R16F *src1, const R16F *src2)
    {
        dst->R = gl::float32ToFloat16((gl::float16ToFloat32(src1->R) + gl::float16ToFloat32(src2->R)) * 0.5f);
    }
};

struct R16G16F
{
    unsigned short R;
    unsigned short G;

    static void average(R16G16F *dst, const R16G16F *src1, const R16G16F *src2)
    {
        dst->R = gl::float32ToFloat16((gl::float16ToFloat32(src1->R) + gl::float16ToFloat32(src2->R)) * 0.5f);
        dst->G = gl::float32ToFloat16((gl::float16ToFloat32(src1->G) + gl::float16ToFloat32(src2->G)) * 0.5f);
    }
};

typedef A16B16G16R16F R16G16B16A16F;

struct A32B32G32R32F
{
    float R;
    float G;
    float B;
    float A;

    static void average(A32B32G32R32F *dst, const A32B32G32R32F *src1, const A32B32G32R32F *src2)
    {
        dst->R = (src1->R + src2->R) * 0.5f;
        dst->G = (src1->G + src2->G) * 0.5f;
        dst->B = (src1->B + src2->B) * 0.5f;
        dst->A = (src1->A + src2->A) * 0.5f;
    }
};

struct R32F
{
    float R;

    static void average(R32F *dst, const R32F *src1, const R32F *src2)
    {
        dst->R = (src1->R + src2->R) * 0.5f;
    }
};

struct R32G32F
{
    float R;
    float G;

    static void average(R32G32F *dst, const R32G32F *src1, const R32G32F *src2)
    {
        dst->R = (src1->R + src2->R) * 0.5f;
        dst->G = (src1->G + src2->G) * 0.5f;
    }
};

struct R32G32B32F
{
    float R;
    float G;
    float B;

    static void average(R32G32B32F *dst, const R32G32B32F *src1, const R32G32B32F *src2)
    {
        dst->R = (src1->R + src2->R) * 0.5f;
        dst->G = (src1->G + src2->G) * 0.5f;
        dst->B = (src1->B + src2->B) * 0.5f;
    }
};

typedef A32B32G32R32F R32G32B32A32F;

struct R10G10B10A2
{
    unsigned int R : 10;
    unsigned int G : 10;
    unsigned int B : 10;
    unsigned int A : 2;

    static void average(R10G10B10A2 *dst, const R10G10B10A2 *src1, const R10G10B10A2 *src2)
    {
        dst->R = (src1->R + src2->R) >> 1;
        dst->G = (src1->G + src2->G) >> 1;
        dst->B = (src1->B + src2->B) >> 1;
        dst->A = (src1->A + src2->A) >> 1;
    }
};

struct R9G9B9E5
{
    unsigned int R : 9;
    unsigned int G : 9;
    unsigned int B : 9;
    unsigned int E : 5;

    static void average(R9G9B9E5 *dst, const R9G9B9E5 *src1, const R9G9B9E5 *src2)
    {
        float r1, g1, b1;
        gl::convert999E5toRGBFloats(*reinterpret_cast<const unsigned int*>(src1), &r1, &g1, &b1);

        float r2, g2, b2;
        gl::convert999E5toRGBFloats(*reinterpret_cast<const unsigned int*>(src2), &r2, &g2, &b2);

        *reinterpret_cast<unsigned int*>(dst) = gl::convertRGBFloatsTo999E5((r1 + r2) * 0.5f, (g1 + g2) * 0.5f, (b1 + b2) * 0.5f);
    }
};

struct R11G11B10F
{
    unsigned int R : 11;
    unsigned int G : 11;
    unsigned int B : 10;

    static void average(R11G11B10F *dst, const R11G11B10F *src1, const R11G11B10F *src2)
    {
        dst->R = gl::float32ToFloat11((gl::float11ToFloat32(src1->R) + gl::float11ToFloat32(src2->R)) * 0.5f);
        dst->G = gl::float32ToFloat11((gl::float11ToFloat32(src1->G) + gl::float11ToFloat32(src2->G)) * 0.5f);
        dst->B = gl::float32ToFloat10((gl::float10ToFloat32(src1->B) + gl::float10ToFloat32(src2->B)) * 0.5f);
    }
};

namespace priv
{

template <typename T>
static inline T *GetPixel(void *data, unsigned int x, unsigned int y, unsigned int z, unsigned int rowPitch, unsigned int depthPitch)
{
    return reinterpret_cast<T*>(reinterpret_cast<unsigned char*>(data) + (x * sizeof(T)) + (y * rowPitch) + (z * depthPitch));
}

template <typename T>
static inline const T *GetPixel(const void *data, unsigned int x, unsigned int y, unsigned int z, unsigned int rowPitch, unsigned int depthPitch)
{
    return reinterpret_cast<const T*>(reinterpret_cast<const unsigned char*>(data) + (x * sizeof(T)) + (y * rowPitch) + (z * depthPitch));
}

template <typename T>
static void GenerateMip_Y(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth,
                          const unsigned char *sourceData, int sourceRowPitch, int sourceDepthPitch,
                          unsigned int destWidth, unsigned int destHeight, unsigned int destDepth,
                          unsigned char *destData, int destRowPitch, int destDepthPitch)
{
    ASSERT(sourceWidth == 1);
    ASSERT(sourceHeight > 1);
    ASSERT(sourceDepth == 1);

    for (unsigned int y = 0; y < destHeight; y++)
    {
        const T *src0 = GetPixel<T>(sourceData, 0, y * 2, 0, sourceRowPitch, sourceDepthPitch);
        const T *src1 = GetPixel<T>(sourceData, 0, y * 2 + 1, 0, sourceRowPitch, sourceDepthPitch);
        T *dst = GetPixel<T>(destData, 0, y, 0, destRowPitch, destDepthPitch);

        T::average(dst, src0, src1);
    }
}

template <typename T>
static void GenerateMip_X(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth,
                          const unsigned char *sourceData, int sourceRowPitch, int sourceDepthPitch,
                          unsigned int destWidth, unsigned int destHeight, unsigned int destDepth,
                          unsigned char *destData, int destRowPitch, int destDepthPitch)
{
    ASSERT(sourceWidth > 1);
    ASSERT(sourceHeight == 1);
    ASSERT(sourceDepth == 1);

    for (unsigned int x = 0; x < destWidth; x++)
    {
        const T *src0 = GetPixel<T>(sourceData, x * 2, 0, 0, sourceRowPitch, sourceDepthPitch);
        const T *src1 = GetPixel<T>(sourceData, x * 2 + 1, 0, 0, sourceRowPitch, sourceDepthPitch);
        T *dst = GetPixel<T>(destData, x, 0, 0, destRowPitch, destDepthPitch);

        T::average(dst, src0, src1);
    }
}

template <typename T>
static void GenerateMip_Z(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth,
                          const unsigned char *sourceData, int sourceRowPitch, int sourceDepthPitch,
                          unsigned int destWidth, unsigned int destHeight, unsigned int destDepth,
                          unsigned char *destData, int destRowPitch, int destDepthPitch)
{
    ASSERT(sourceWidth == 1);
    ASSERT(sourceHeight == 1);
    ASSERT(sourceDepth > 1);

    for (unsigned int z = 0; z < destDepth; z++)
    {
        const T *src0 = GetPixel<T>(sourceData, 0, 0, z * 2, sourceRowPitch, sourceDepthPitch);
        const T *src1 = GetPixel<T>(sourceData, 0, 0, z * 2 + 1, sourceRowPitch, sourceDepthPitch);
        T *dst = GetPixel<T>(destData, 0, 0, z, destRowPitch, destDepthPitch);

        T::average(dst, src0, src1);
    }
}

template <typename T>
static void GenerateMip_XY(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth,
                           const unsigned char *sourceData, int sourceRowPitch, int sourceDepthPitch,
                           unsigned int destWidth, unsigned int destHeight, unsigned int destDepth,
                           unsigned char *destData, int destRowPitch, int destDepthPitch)
{
    ASSERT(sourceWidth > 1);
    ASSERT(sourceHeight > 1);
    ASSERT(sourceDepth == 1);

    for (unsigned int y = 0; y < destHeight; y++)
    {
        for (unsigned int x = 0; x < destWidth; x++)
        {
            const T *src0 = GetPixel<T>(sourceData, x * 2, y * 2, 0, sourceRowPitch, sourceDepthPitch);
            const T *src1 = GetPixel<T>(sourceData, x * 2, y * 2 + 1, 0, sourceRowPitch, sourceDepthPitch);
            const T *src2 = GetPixel<T>(sourceData, x * 2 + 1, y * 2, 0, sourceRowPitch, sourceDepthPitch);
            const T *src3 = GetPixel<T>(sourceData, x * 2 + 1, y * 2 + 1, 0, sourceRowPitch, sourceDepthPitch);
            T *dst = GetPixel<T>(destData, x, y, 0, destRowPitch, destDepthPitch);

            T tmp0, tmp1;

            T::average(&tmp0, src0, src1);
            T::average(&tmp1, src2, src3);
            T::average(dst, &tmp0, &tmp1);
        }
    }
}

template <typename T>
static void GenerateMip_YZ(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth,
                           const unsigned char *sourceData, int sourceRowPitch, int sourceDepthPitch,
                           unsigned int destWidth, unsigned int destHeight, unsigned int destDepth,
                           unsigned char *destData, int destRowPitch, int destDepthPitch)
{
    ASSERT(sourceWidth == 1);
    ASSERT(sourceHeight > 1);
    ASSERT(sourceDepth > 1);

    for (unsigned int z = 0; z < destDepth; z++)
    {
        for (unsigned int y = 0; y < destHeight; y++)
        {
            const T *src0 = GetPixel<T>(sourceData, 0, y * 2, z * 2, sourceRowPitch, sourceDepthPitch);
            const T *src1 = GetPixel<T>(sourceData, 0, y * 2, z * 2 + 1, sourceRowPitch, sourceDepthPitch);
            const T *src2 = GetPixel<T>(sourceData, 0, y * 2 + 1, z * 2, sourceRowPitch, sourceDepthPitch);
            const T *src3 = GetPixel<T>(sourceData, 0, y * 2 + 1, z * 2 + 1, sourceRowPitch, sourceDepthPitch);
            T *dst = GetPixel<T>(destData, 0, y, z, destRowPitch, destDepthPitch);

            T tmp0, tmp1;

            T::average(&tmp0, src0, src1);
            T::average(&tmp1, src2, src3);
            T::average(dst, &tmp0, &tmp1);
        }
    }
}

template <typename T>
static void GenerateMip_XZ(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth,
                           const unsigned char *sourceData, int sourceRowPitch, int sourceDepthPitch,
                           unsigned int destWidth, unsigned int destHeight, unsigned int destDepth,
                           unsigned char *destData, int destRowPitch, int destDepthPitch)
{
    ASSERT(sourceWidth > 1);
    ASSERT(sourceHeight == 1);
    ASSERT(sourceDepth > 1);

    for (unsigned int z = 0; z < destDepth; z++)
    {
        for (unsigned int x = 0; x < destWidth; x++)
        {
            const T *src0 = GetPixel<T>(sourceData, x * 2, 0, z * 2, sourceRowPitch, sourceDepthPitch);
            const T *src1 = GetPixel<T>(sourceData, x * 2, 0, z * 2 + 1, sourceRowPitch, sourceDepthPitch);
            const T *src2 = GetPixel<T>(sourceData, x * 2 + 1, 0, z * 2, sourceRowPitch, sourceDepthPitch);
            const T *src3 = GetPixel<T>(sourceData, x * 2 + 1, 0, z * 2 + 1, sourceRowPitch, sourceDepthPitch);
            T *dst = GetPixel<T>(destData, x, 0, z, destRowPitch, destDepthPitch);

            T tmp0, tmp1;

            T::average(&tmp0, src0, src1);
            T::average(&tmp1, src2, src3);
            T::average(dst, &tmp0, &tmp1);
        }
    }
}

template <typename T>
static void GenerateMip_XYZ(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth,
                            const unsigned char *sourceData, int sourceRowPitch, int sourceDepthPitch,
                            unsigned int destWidth, unsigned int destHeight, unsigned int destDepth,
                            unsigned char *destData, int destRowPitch, int destDepthPitch)
{
    ASSERT(sourceWidth > 1);
    ASSERT(sourceHeight > 1);
    ASSERT(sourceDepth > 1);

    for (unsigned int z = 0; z < destDepth; z++)
    {
        for (unsigned int y = 0; y < destHeight; y++)
        {
            for (unsigned int x = 0; x < destWidth; x++)
            {
                const T *src0 = GetPixel<T>(sourceData, x * 2, y * 2, z * 2, sourceRowPitch, sourceDepthPitch);
                const T *src1 = GetPixel<T>(sourceData, x * 2, y * 2, z * 2 + 1, sourceRowPitch, sourceDepthPitch);
                const T *src2 = GetPixel<T>(sourceData, x * 2, y * 2 + 1, z * 2, sourceRowPitch, sourceDepthPitch);
                const T *src3 = GetPixel<T>(sourceData, x * 2, y * 2 + 1, z * 2 + 1, sourceRowPitch, sourceDepthPitch);
                const T *src4 = GetPixel<T>(sourceData, x * 2 + 1, y * 2, z * 2, sourceRowPitch, sourceDepthPitch);
                const T *src5 = GetPixel<T>(sourceData, x * 2 + 1, y * 2, z * 2 + 1, sourceRowPitch, sourceDepthPitch);
                const T *src6 = GetPixel<T>(sourceData, x * 2 + 1, y * 2 + 1, z * 2, sourceRowPitch, sourceDepthPitch);
                const T *src7 = GetPixel<T>(sourceData, x * 2 + 1, y * 2 + 1, z * 2 + 1, sourceRowPitch, sourceDepthPitch);
                T *dst = GetPixel<T>(destData, x, y, z, destRowPitch, destDepthPitch);

                T tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;

                T::average(&tmp0, src0, src1);
                T::average(&tmp1, src2, src3);
                T::average(&tmp2, src4, src5);
                T::average(&tmp3, src6, src7);

                T::average(&tmp4, &tmp0, &tmp1);
                T::average(&tmp5, &tmp2, &tmp3);

                T::average(dst, &tmp4, &tmp5);
            }
        }
    }
}


typedef void (*MipGenerationFunction)(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth,
                                      const unsigned char *sourceData, int sourceRowPitch, int sourceDepthPitch,
                                      unsigned int destWidth, unsigned int destHeight, unsigned int destDepth,
                                      unsigned char *destData, int destRowPitch, int destDepthPitch);

template <typename T>
static MipGenerationFunction GetMipGenerationFunction(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth)
{
    unsigned char index = ((sourceWidth > 1)  ? 1 : 0) |
                          ((sourceHeight > 1) ? 2 : 0) |
                          ((sourceDepth > 1)  ? 4 : 0);

    switch (index)
    {
      case 1:  return GenerateMip_X<T>;   // W x 1 x 1
      case 2:  return GenerateMip_Y<T>;   // 1 x H x 1
      case 3:  return GenerateMip_XY<T>;  // W x H x 1
      case 4:  return GenerateMip_Z<T>;   // 1 x 1 x D
      case 5:  return GenerateMip_XZ<T>;  // W x 1 x D
      case 6:  return GenerateMip_YZ<T>;  // 1 x H x D
      case 7:  return GenerateMip_XYZ<T>; // W x H x D
      default: return NULL;
    }
}

}

template <typename T>
static void GenerateMip(unsigned int sourceWidth, unsigned int sourceHeight, unsigned int sourceDepth,
                        const unsigned char *sourceData, int sourceRowPitch, int sourceDepthPitch,
                        unsigned char *destData, int destRowPitch, int destDepthPitch)
{
    unsigned int mipWidth = std::max(1U, sourceWidth >> 1);
    unsigned int mipHeight = std::max(1U, sourceHeight >> 1);
    unsigned int mipDepth = std::max(1U, sourceDepth >> 1);

    priv::MipGenerationFunction generationFunction = priv::GetMipGenerationFunction<T>(sourceWidth, sourceHeight, sourceDepth);
    ASSERT(generationFunction != NULL);

    generationFunction(sourceWidth, sourceHeight, sourceDepth, sourceData, sourceRowPitch, sourceDepthPitch,
                       mipWidth, mipHeight, mipDepth, destData, destRowPitch, destDepthPitch);
}

}

#endif // LIBGLESV2_RENDERER_GENERATEMIP_H_