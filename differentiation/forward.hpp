#ifndef CENTRAL_DERIVATIVE_HPP
#define CENTRAL_DERIVATIVE_HPP

#include<limits>
#include<type_traits>
#include<cmath>

namespace numpp{
	namespace derivative{
		template<
			typename Func,
			typename T
		>
			constexpr auto forward(Func&& f, T&& x, T&& h){
				return (f(x+h)-f(x))/h;
			}

		template<
			typename Func,
			typename T,
			typename = std::enable_if_t<std::is_floating_point<T>::value>
		>
			constexpr auto forward(Func&& f, T x){
				auto h = x*std::sqrt(std::numeric_limits<T>::epsilon());
				return (f(x+h)-f(x))/h;
			}

		template<
			typename Func,
			typename T,
			typename U,
			typename = std::enable_if_t<
				std::is_floating_point<T>::value and
				std::is_arithmetic<U>::value
			>
		>
			constexpr auto forward(Func&& f, T x, U y){
				auto h = x*std::sqrt(std::numeric_limits<T>::epsilon());
				return (f(x+h)-y)/h;
			}

		template<
			typename Func,
			typename T,
			typename U
		>
			constexpr auto forward(Func&& f, T&& x, U&& y, T&& h){
				return (f(x+h)-y)/h;
			}
	}
}

#endif
