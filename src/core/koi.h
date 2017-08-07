#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef KOI_CORE_KOI_H
#define KOI_CORE_KOI_H

#include"platform.h"

// Global Include Files
#include <unordered_map>
#include <type_traits>
#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <cinttypes>
#include <cassert>
#include <cstring>
#include <cmath>

#include <glog/logging.h>

// Platform-specific definitions
#include <stdint.h>
#if defined(KOI_IN_MSVC)
#include <float.h>
#include <intrin.h>
#pragma warning(disable : 4305)  // double constant assigned to float
#pragma warning(disable : 4244)  // int -> float conversion
#pragma warning(disable : 4843)  // double -> float conversion
#endif

namespace koi
{

//#define KOI_FLOAT_AS_DOUBLE
#ifdef KOI_FLOAT_AS_DOUBLE
using Float = double;
#else
using Float = float;
#endif 

//±‹√‚«∞÷√…˘√˜

// Global Constants

static constexpr Float MaxFloat = std::numeric_limits<Float>::max();
static constexpr Float Infinity = std::numeric_limits<Float>::infinity();

static constexpr Float MachineEpsilon = std::numeric_limits<Float>::epsilon() * 0.5;

static constexpr Float ShadowEpsilon = 0.0001f;
static constexpr Float Pi = 3.14159265358979323846;
static constexpr Float InvPi = 0.31830988618379067154;
static constexpr Float Inv2Pi = 0.15915494309189533577;
static constexpr Float Inv4Pi = 0.07957747154594766788;
static constexpr Float PiOver2 = 1.57079632679489661923;
static constexpr Float PiOver4 = 0.78539816339744830961;
static constexpr Float Sqrt2 = 1.41421356237309504880;

inline Float to_radians(Float deg) { return (Pi / 180) * deg; }

inline Float to_degrees(Float rad) { return (180 / Pi) * rad; }

template <typename T, typename U, typename V>
inline T clamp(T val, U low, V high)
{
	if (val < low)
		return low;
	else if (val > high)
		return high;
	else
		return val;
}

inline Float gamma(int n) 
{
	return (n * MachineEpsilon) / (1 - n * MachineEpsilon);
}

}	//namespace koi


#endif //KOI_CORE_KOI_H
