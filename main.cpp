#include <iostream>
#include "promise.h"

int main()
{
    auto a = ipromise::makePromise([]() { int x; std::cin>>x; std::cout<<x+1<<'\n'; return x+2; }, ipromise::executionPolicy::synchronous);
    auto b = a
                 ->then([](int x) { std::cout<<x<<'\n'; return x+1; })
                 ->then([](int x) { std::cout<<x<<'\n'; return x+1; })
                 ->then([](int x) { std::cout<<x<<'\n'; return x+1; })
                 ->then([](int x) { std::cout<<x<<'\n'; return x+1; });

    auto c = ipromise::makePromise([]() { std::cout<<11<<'\n'; return 10; }, ipromise::executionPolicy::synchronous);
    while (!ipromise::loopEmpty())
        ipromise::loop();
    c->then([](int x) { std::cout<<x<<'\n'; return x+1; });

    return 0;
}