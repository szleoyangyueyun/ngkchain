#include <ngk/vm/backend.hpp>
#include <ngk/vm/error_codes.hpp>
#include <ngk/vm/host_function.hpp>
#include <ngk/vm/watchdog.hpp>

#include <iostream>

using namespace ngk;
using namespace ngk::vm;

#include "hello.wasm.hpp"

namespace ngk { namespace vm {

   template <>
   struct wasm_type_converter<const char*> : linear_memory_access {
      const char* from_wasm(const void* val) { validate_c_str(val); return static_cast<const char*>(val); }
   };

}}

// example of host function as a raw C style function
void ngk_assert(bool test, const char* msg) {
   if (!test) {
      std::cout << msg << std::endl;
      throw 0;
   }
}

void print_num(uint64_t n) { std::cout << "Number : " << n << "\n"; }

struct example_host_methods {
   // example of a host "method"
   void print_name(const char* nm) { std::cout << "Name : " << nm << " " << field << "\n"; }
   // example of another type of host function
   static void* memset(void* ptr, int x, size_t n) { return ::memset(ptr, x, n); }
   std::string  field = "";
};

/**
 * Simple implementation of an interpreter using ngk-vm.
 */
int main(int argc, char** argv) {
   if (argc < 4) {
      std::cerr << "Please enter three numbers\n";
      return -1;
   }
   // Thread specific `allocator` used for wasm linear memory.
   wasm_allocator wa;
   // Specific the backend with example_host_methods for host functions.
   using backend_t = ngk::vm::backend<example_host_methods>;
   using rhf_t     = ngk::vm::registered_host_functions<example_host_methods>;

   // register print_num
   rhf_t::add<nullptr_t, &print_num, wasm_allocator>("env", "print_num");
   // register ngk_assert
   rhf_t::add<nullptr_t, &ngk_assert, wasm_allocator>("env", "ngk_assert");
   // register print_name
   rhf_t::add<example_host_methods, &example_host_methods::print_name, wasm_allocator>("env", "print_name");
   // finally register memset
   rhf_t::add<nullptr_t, &example_host_methods::memset, wasm_allocator>("env", "memset");

   watchdog wd{std::chrono::seconds(3)};
   try {
      // Instaniate a new backend using the wasm provided.
      backend_t bkend(hello_wasm, rhf_t{});

      // Point the backend to the allocator you want it to use.
      bkend.set_wasm_allocator(&wa);
      bkend.initialize();
      // Resolve the host functions indices.

      // Instaniate a "host"
      example_host_methods ehm;
      ehm.field = "testing";
      // Execute apply.
      bkend(&ehm, "env", "apply", (uint64_t)std::atoi(argv[1]), (uint64_t)std::atoi(argv[2]),
            (uint64_t)std::atoi(argv[3]));

   } catch (...) { std::cerr << "ngk-vm interpreter error\n"; }
   return 0;
}
