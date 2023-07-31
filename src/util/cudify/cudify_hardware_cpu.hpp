#ifndef CUDIFY_HARDWARE_COMMON_HPP_
#define CUDIFY_HARDWARE_COMMON_HPP_


#include <initializer_list>
#include <cstring>
#include "util/cuda_util.hpp"

#if defined(CUDIFY_USE_SEQUENTIAL) || defined(CUDIFY_USE_OPENMP)

#ifndef OPENMP_MAX_NUM_THREADS
#define OPENMP_MAX_NUM_THREADS 896
#endif

/**
 * CUDA error types
 */
enum cudaError
{

    cudaSuccess                           =      0,
    cudaErrorInvalidValue                 =     1,
    cudaErrorMemoryAllocation             =      2,
    cudaErrorInitializationError          =      3,
    cudaErrorCudartUnloading              =     4,
    cudaErrorProfilerDisabled             =     5,
    cudaErrorProfilerNotInitialized       =     6,
    cudaErrorProfilerAlreadyStarted       =     7,
    cudaErrorProfilerAlreadyStopped       =    8,
    cudaErrorInvalidConfiguration         =      9,
    cudaErrorInvalidPitchValue            =     12,
    cudaErrorInvalidSymbol                =     13,
    cudaErrorInvalidHostPointer           =     16,
    cudaErrorInvalidDevicePointer         =     17,
    cudaErrorInvalidTexture               =     18,
    cudaErrorInvalidTextureBinding        =     19,
    cudaErrorInvalidChannelDescriptor     =     20,
    cudaErrorInvalidMemcpyDirection       =     21,
    cudaErrorAddressOfConstant            =     22,
    cudaErrorTextureFetchFailed           =     23,
    cudaErrorTextureNotBound              =     24,
    cudaErrorSynchronizationError         =     25,
    cudaErrorInvalidFilterSetting         =     26,
    cudaErrorInvalidNormSetting           =     27,
    cudaErrorMixedDeviceExecution         =     28,
    cudaErrorNotYetImplemented            =     31,
    cudaErrorMemoryValueTooLarge          =     32,
    cudaErrorStubLibrary                  =     34,
    cudaErrorInsufficientDriver           =     35,
    cudaErrorCallRequiresNewerDriver      =     36,
    cudaErrorInvalidSurface               =     37,
    cudaErrorDuplicateVariableName        =     43,
    cudaErrorDuplicateTextureName         =     44,
    cudaErrorDuplicateSurfaceName         =     45,
    cudaErrorDevicesUnavailable           =     46,
    cudaErrorIncompatibleDriverContext    =     49,
    cudaErrorMissingConfiguration         =      52,
    cudaErrorPriorLaunchFailure           =      53,
    cudaErrorLaunchMaxDepthExceeded       =     65,
    cudaErrorLaunchFileScopedTex          =     66,
    cudaErrorLaunchFileScopedSurf         =     67,
    cudaErrorSyncDepthExceeded            =     68,
    cudaErrorLaunchPendingCountExceeded   =     69,
    cudaErrorInvalidDeviceFunction        =      98,
    cudaErrorNoDevice                     =     100,
    cudaErrorInvalidDevice                =     101,
    cudaErrorDeviceNotLicensed            =     102,
    cudaErrorSoftwareValidityNotEstablished  =     103,
    cudaErrorStartupFailure               =    127,
    cudaErrorInvalidKernelImage           =     200,
    cudaErrorDeviceUninitialized          =     201,
    cudaErrorMapBufferObjectFailed        =     205,
    cudaErrorUnmapBufferObjectFailed      =     206,
    cudaErrorArrayIsMapped                =     207,
    cudaErrorAlreadyMapped                =     208,
    cudaErrorNoKernelImageForDevice       =     209,
    cudaErrorAlreadyAcquired              =     210,
    cudaErrorNotMapped                    =     211,
    cudaErrorNotMappedAsArray             =     212,
    cudaErrorNotMappedAsPointer           =     213,
    cudaErrorECCUncorrectable             =     214,
    cudaErrorUnsupportedLimit             =     215,
    cudaErrorDeviceAlreadyInUse           =     216,
    cudaErrorPeerAccessUnsupported        =     217,
    cudaErrorInvalidPtx                   =     218,
    cudaErrorInvalidGraphicsContext       =     219,
    cudaErrorNvlinkUncorrectable          =     220,
    cudaErrorJitCompilerNotFound          =     221,
    cudaErrorUnsupportedPtxVersion        =     222,
    cudaErrorJitCompilationDisabled       =     223,
    cudaErrorUnsupportedExecAffinity      =     224,
    cudaErrorInvalidSource                =     300,
    cudaErrorFileNotFound                 =     301,
    cudaErrorSharedObjectSymbolNotFound   =     302,
    cudaErrorSharedObjectInitFailed       =     303,
    cudaErrorOperatingSystem              =     304,
    cudaErrorInvalidResourceHandle        =     400,
    cudaErrorIllegalState                 =     401,
    cudaErrorSymbolNotFound               =     500,
    cudaErrorNotReady                     =     600,
    cudaErrorIllegalAddress               =     700,
    cudaErrorLaunchOutOfResources         =      701,
    cudaErrorLaunchTimeout                =      702,
    cudaErrorLaunchIncompatibleTexturing  =     703,
    cudaErrorPeerAccessAlreadyEnabled     =     704,
    cudaErrorPeerAccessNotEnabled         =     705,
    cudaErrorSetOnActiveProcess           =     708,
    cudaErrorContextIsDestroyed           =     709,
    cudaErrorAssert                        =    710,
    cudaErrorTooManyPeers                 =     711,
    cudaErrorHostMemoryAlreadyRegistered  =     712,
    cudaErrorHostMemoryNotRegistered      =     713,
    cudaErrorHardwareStackError           =     714,
    cudaErrorIllegalInstruction           =     715,
    cudaErrorMisalignedAddress            =     716,
    cudaErrorInvalidAddressSpace          =     717,
    cudaErrorInvalidPc                    =     718,
    cudaErrorLaunchFailure                =      719,
    cudaErrorCooperativeLaunchTooLarge    =     720,
    cudaErrorNotPermitted                 =     800,
    cudaErrorNotSupported                 =     801,
    cudaErrorSystemNotReady               =     802,
    cudaErrorSystemDriverMismatch         =     803,
    cudaErrorCompatNotSupportedOnDevice   =     804,
    cudaErrorMpsConnectionFailed          =     805,
    cudaErrorMpsRpcFailure                =     806,
    cudaErrorMpsServerNotReady            =     807,
    cudaErrorMpsMaxClientsReached         =     808,
    cudaErrorMpsMaxConnectionsReached     =     809,
    cudaErrorStreamCaptureUnsupported     =    900,
    cudaErrorStreamCaptureInvalidated     =    901,
    cudaErrorStreamCaptureMerge           =    902,
    cudaErrorStreamCaptureUnmatched       =    903,
    cudaErrorStreamCaptureUnjoined        =    904,
    cudaErrorStreamCaptureIsolation       =    905,
    cudaErrorStreamCaptureImplicit        =    906,
    cudaErrorCapturedEvent                =    907,
    cudaErrorStreamCaptureWrongThread     =    908,
    cudaErrorTimeout                      =    909,
    cudaErrorGraphExecUpdateFailure       =    910,
    cudaErrorUnknown                      =    999,
    cudaErrorApiFailureBase               =  10000
};

typedef cudaError cudaError_t;

struct uint3
{
    unsigned int x, y, z;
};

struct dim3
{
    unsigned int x, y, z;

    constexpr dim3(unsigned int vx = 1, unsigned int vy = 1, unsigned int vz = 1) : x(vx), y(vy), z(vz) {}
    constexpr dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    constexpr operator uint3(void) const { return uint3{x, y, z}; }

    constexpr dim3(const dim3 & d) : x(d.x), y(d.y), z(d.z) {}

    template<typename T>
    dim3(const std::initializer_list<T> & list) 
    {
        auto it = list.begin();

        x = *it;
        ++it;
        y = *it;
        ++it;
        z = *it;
    }
};

/**
 * CUDA memory copy types
 */
enum  cudaMemcpyKind
{
    cudaMemcpyHostToHost          =   0,      /**< Host   -> Host */
    cudaMemcpyHostToDevice        =   1,      /**< Host   -> Device */
    cudaMemcpyDeviceToHost        =   2,      /**< Device -> Host */
    cudaMemcpyDeviceToDevice      =   3,      /**< Device -> Device */
    cudaMemcpyDefault             =   4       /**< Direction of the transfer is inferred from the pointer values. Requires unified virtual addressing */
};

const static char unk_error[] = "Unknown error";

static const char* cudaGetErrorName ( cudaError error )
{
    return unk_error;
}

static const char* cudaGetErrorString ( cudaError error )
{
    return unk_error;
}

static void cudaDeviceSynchronize()
{}

static cudaError cudaMemcpyFromSymbol(void * dev_mem,const unsigned char * global_cuda_error_array,size_t sz)
{
    memcpy(dev_mem,global_cuda_error_array,sz);
    return cudaError::cudaSuccess;
}

static cudaError cudaMemcpyToSymbol(unsigned char * global_cuda_error_array, const void * dev_mem,size_t sz, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyHostToDevice )
{
    memcpy(global_cuda_error_array + offset,dev_mem,sz);
    return cudaError::cudaSuccess;
}

static cudaError cudaMemcpy( void* dst, const void* src, size_t count, cudaMemcpyKind kind)
{
    memcpy(dst,src,count);

    return cudaError::cudaSuccess;
}


static cudaError cudaHostGetDevicePointer( void** pDevice, void* pHost, unsigned int  flags)
{
    *pDevice = pHost;

    return cudaError::cudaSuccess;
}

struct float3
{
    float x,y,z;
};

struct float4
{
    float x,y,z,w;
};

static __inline__ __host__ __device__ float4 make_float4(float x, float y, float z, float w)
{
  float4 t; t.x = x; t.y = y; t.z = z; t.w = w; return t;
}



#endif

#endif
