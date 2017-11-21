#pragma once
#include "abilities.hpp"
#include "types.hpp"
#include "access.hpp"
#include "kvasir/mpl/mpl.hpp"

namespace kvasir{
    namespace abcd{
        namespace detail{
            using namespace ::kvasir::mpl;
            template<typename A, typename C>
            using filter_by_capability = call<unpack<filter<push_back<C,cfe<has_ability>>>>,A>;
        }
		namespace detail {
			template<typename A, typename F, typename...Ts>
			void for_each_helper(A& access, F l, ::kvasir::mpl::list<Ts...>) {
				int r[] = { 0,(l(access[index_t<Ts>{}]),0)... };
				(void)r;
			}
		}
    }
}