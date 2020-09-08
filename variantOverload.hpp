#ifndef VARIANT_OVERLOAD_H
#define VARIANT_OVERLOAD_H

#include<variant>
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

#endif
