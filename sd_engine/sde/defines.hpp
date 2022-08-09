#pragma once

#include <cstdint>
#include <memory>

namespace sd
{

// ptrs
template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T>
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

} // namespace sd

// api
#ifdef SD_WINDOWS
	#ifdef SD_EXPORT
		#define SD_API __declspec(dllexport)
	#else
		#define SD_API __declspec(dllimport)
	#endif
#else
	#define SD_API
#endif

// utility
#define BIT(x) (1 << x)