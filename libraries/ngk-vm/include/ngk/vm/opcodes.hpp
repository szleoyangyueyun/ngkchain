#pragma once
#include <ngk/vm/opcodes_def.hpp>
#include <ngk/vm/variant.hpp>

#include <map>

namespace ngk { namespace vm {
   enum opcodes {
      NGK_VM_CONTROL_FLOW_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_BR_TABLE_OP(NGK_VM_CREATE_ENUM)
      NGK_VM_RETURN_OP(NGK_VM_CREATE_ENUM)
      NGK_VM_CALL_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_CALL_IMM_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_PARAMETRIC_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_VARIABLE_ACCESS_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_MEMORY_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_I32_CONSTANT_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_I64_CONSTANT_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_F32_CONSTANT_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_F64_CONSTANT_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_COMPARISON_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_NUMERIC_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_CONVERSION_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_EXIT_OP(NGK_VM_CREATE_ENUM)
      NGK_VM_EMPTY_OPS(NGK_VM_CREATE_ENUM)
      NGK_VM_ERROR_OPS(NGK_VM_CREATE_ENUM)
   };
   
   struct opcode_utils {
      std::map<uint16_t, std::string> opcode_map{
         NGK_VM_CONTROL_FLOW_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_BR_TABLE_OP(NGK_VM_CREATE_MAP)
         NGK_VM_RETURN_OP(NGK_VM_CREATE_MAP)
         NGK_VM_CALL_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_CALL_IMM_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_PARAMETRIC_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_VARIABLE_ACCESS_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_MEMORY_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_I32_CONSTANT_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_I64_CONSTANT_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_F32_CONSTANT_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_F64_CONSTANT_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_COMPARISON_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_NUMERIC_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_CONVERSION_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_EXIT_OP(NGK_VM_CREATE_MAP)
         NGK_VM_EMPTY_OPS(NGK_VM_CREATE_MAP)
         NGK_VM_ERROR_OPS(NGK_VM_CREATE_MAP)
      };
   }; 

   enum imm_types {
      none,
      block_imm,
      varuint32_imm,
      br_table_imm,
   };


   NGK_VM_CONTROL_FLOW_OPS(NGK_VM_CREATE_CONTROL_FLOW_TYPES)
   NGK_VM_BR_TABLE_OP(NGK_VM_CREATE_BR_TABLE_TYPE)
   NGK_VM_RETURN_OP(NGK_VM_CREATE_CONTROL_FLOW_TYPES)
   NGK_VM_CALL_OPS(NGK_VM_CREATE_CALL_TYPES)
   NGK_VM_CALL_IMM_OPS(NGK_VM_CREATE_CALL_IMM_TYPES)
   NGK_VM_PARAMETRIC_OPS(NGK_VM_CREATE_TYPES)
   NGK_VM_VARIABLE_ACCESS_OPS(NGK_VM_CREATE_VARIABLE_ACCESS_TYPES)
   NGK_VM_MEMORY_OPS(NGK_VM_CREATE_MEMORY_TYPES)
   NGK_VM_I32_CONSTANT_OPS(NGK_VM_CREATE_I32_CONSTANT_TYPE)
   NGK_VM_I64_CONSTANT_OPS(NGK_VM_CREATE_I64_CONSTANT_TYPE)
   NGK_VM_F32_CONSTANT_OPS(NGK_VM_CREATE_F32_CONSTANT_TYPE)
   NGK_VM_F64_CONSTANT_OPS(NGK_VM_CREATE_F64_CONSTANT_TYPE)
   NGK_VM_COMPARISON_OPS(NGK_VM_CREATE_TYPES)
   NGK_VM_NUMERIC_OPS(NGK_VM_CREATE_TYPES)
   NGK_VM_CONVERSION_OPS(NGK_VM_CREATE_TYPES)
   NGK_VM_EXIT_OP(NGK_VM_CREATE_EXIT_TYPE)
   NGK_VM_EMPTY_OPS(NGK_VM_CREATE_TYPES)
   NGK_VM_ERROR_OPS(NGK_VM_CREATE_TYPES)

   using opcode = variant<
      NGK_VM_CONTROL_FLOW_OPS(NGK_VM_IDENTITY)
      NGK_VM_BR_TABLE_OP(NGK_VM_IDENTITY)
      NGK_VM_RETURN_OP(NGK_VM_IDENTITY)
      NGK_VM_CALL_OPS(NGK_VM_IDENTITY)
      NGK_VM_CALL_IMM_OPS(NGK_VM_IDENTITY)
      NGK_VM_PARAMETRIC_OPS(NGK_VM_IDENTITY)
      NGK_VM_VARIABLE_ACCESS_OPS(NGK_VM_IDENTITY)
      NGK_VM_MEMORY_OPS(NGK_VM_IDENTITY)
      NGK_VM_I32_CONSTANT_OPS(NGK_VM_IDENTITY)
      NGK_VM_I64_CONSTANT_OPS(NGK_VM_IDENTITY)
      NGK_VM_F32_CONSTANT_OPS(NGK_VM_IDENTITY)
      NGK_VM_F64_CONSTANT_OPS(NGK_VM_IDENTITY)
      NGK_VM_COMPARISON_OPS(NGK_VM_IDENTITY)
      NGK_VM_NUMERIC_OPS(NGK_VM_IDENTITY)
      NGK_VM_CONVERSION_OPS(NGK_VM_IDENTITY)
      NGK_VM_EXIT_OP(NGK_VM_IDENTITY)
      NGK_VM_EMPTY_OPS(NGK_VM_IDENTITY)
      NGK_VM_ERROR_OPS(NGK_VM_IDENTITY_END)
      >;
}} // namespace ngk::vm