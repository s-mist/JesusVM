#ifndef JESUSVM_MODULEWEB_INCLUDE_MODULEWEB_MODULE_INFO_H
#define JESUSVM_MODULEWEB_INCLUDE_MODULEWEB_MODULE_INFO_H

#include "moduleweb/class_info.h"
#include "moduleweb/constant_info.h"
#include "moduleweb/function_info.h"

#define MODULEWEB_MAGIC_NUMBER 0x4E696765

#ifdef __cplusplus
extern "C" {
#endif

typedef struct moduleweb_module_info {
    u32 magic;
    u16 bytecode_version;
    u16 name_index;

    moduleweb_attribute_array attributes;

    u16 constant_pool_size;
    moduleweb_constant_info* constant_pool; // [constant_pool_size]

    u16 class_count;
    moduleweb_class_info* classes;

    u16 function_count;
    moduleweb_function_info* functions;
} moduleweb_module_info;

int moduleweb_module_info_init(moduleweb_module_info* info, moduleweb_instream* stream);
void moduleweb_module_info_uninit(moduleweb_module_info* info);

int moduleweb_module_constant_get_ascii(const moduleweb_module_info* module, u16 i, moduleweb_constant_ascii_info** result);
int moduleweb_module_constant_get_name(const moduleweb_module_info* module, u16 i, moduleweb_constant_name_info** result);
int moduleweb_module_constant_get_module_ref(const moduleweb_module_info* module, u16 i, moduleweb_constant_module_ref_info** result);
int moduleweb_module_constant_get_function(const moduleweb_module_info* module, u16 i, moduleweb_constant_function_info** result);

#ifdef __cplusplus
}
#endif

#endif //JESUSVM_MODULEWEB_INCLUDE_MODULEWEB_MODULE_INFO_H
