#ifndef VV_DEFINES_INCLUDED
#define VV_DEFINES_INCLUDED

#include <memory>
#include <cstdint>

namespace vv
{

// ptrs
template <typename T>
using Scope = std::unique_ptr<T>;

template <typename T>
using Ref = std::shared_ptr<T>;

// types
using f32 = float;
using f64 = double;

using i64 = int64_t;
using u64 = uint64_t;

using i32 = int32_t;
using u32 = uint32_t;

using i16 = int16_t;
using u16 = uint16_t;

using i8 = int8_t;
using u8 = uint8_t;

template<u32 bit_pos>
constexpr u64 bit() { return (u64)1 << bit_pos; }

} // namespace vv

// api
#ifdef VV_WINDOWS
	#ifdef VV_EXPORT
		#define VV_API __declspec(dllexport)
	#else
		#define VV_API __declspec(dllimport)
	#endif
#else
	#define VV_API
#endif


#endif