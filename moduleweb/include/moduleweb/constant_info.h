#ifndef JESUSVM_MODULEWEB_INCLUDE_MODULEWEB_CONSTANT_INFO_H
#define JESUSVM_MODULEWEB_INCLUDE_MODULEWEB_CONSTANT_INFO_H 1

#include "moduleweb/attribute_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum moduleweb_constant_type : u8 {
    MODULEWEB_CONSTANT_TYPE_ASCII = 0,
    MODULEWEB_CONSTANT_TYPE_NAME = 1,
    MODULEWEB_CONSTANT_TYPE_MODULE_REF = 2,
    MODULEWEB_CONSTANT_TYPE_FUNCTION_REF = 3,
    MODULEWEB_CONSTANT_TYPE_CLASS_REF = 4,
    MODULEWEB_CONSTANT_TYPE_FIELD_REF = 5,
} moduleweb_constant_type;

typedef struct moduleweb_constant_ascii_info {
    u32 length;
    u8* bytes;
} moduleweb_constant_ascii_info;

typedef struct moduleweb_constant_name_info {
    u16 name_index; // ascii
    u16 descriptor_index; // ascii
} moduleweb_constant_name_info;

typedef struct moduleweb_constant_module_ref_info {
    u16 name_index; // ascii
} moduleweb_constant_module_ref_info;

typedef struct moduleweb_constant_function_ref_info {
    u16 module_index; // module_ref
    u16 name_info_index; // name
} moduleweb_constant_function_ref_info;

typedef struct moduleweb_constant_class_ref_info {
    u16 module_index; // module_ref
    u16 name_index; // ascii
} moduleweb_constant_class_ref_info;

typedef struct moduleweb_constant_field_ref_info {
    u16 class_index; // class_ref
    u16 name_info_index; // name
} moduleweb_constant_field_ref_info;

typedef struct moduleweb_constant_info {
    moduleweb_constant_type type;
    union {
        moduleweb_constant_ascii_info ascii_info;
        moduleweb_constant_name_info name_info;
        moduleweb_constant_module_ref_info module_ref_info;
        moduleweb_constant_function_ref_info function_ref_info;
        moduleweb_constant_class_ref_info class_ref_info;
        moduleweb_constant_field_ref_info field_ref_info;
    };
} moduleweb_constant_info;

int moduleweb_constant_info_init(moduleweb_constant_info* info, moduleweb_instream* stream);
void moduleweb_constant_info_uninit(moduleweb_constant_info* info);

int moduleweb_constant_info_emit_bytes(moduleweb_constant_info* info, moduleweb_outstream* stream);
void moduleweb_constant_info_print(moduleweb_constant_info* info, const moduleweb_module_info* module, u32 indent, u16 index);

int moduleweb_constant_info_ascii_compare(moduleweb_constant_ascii_info* s1, const char* s2);

#ifdef __cplusplus
}
#endif

#endif //JESUSVM_MODULEWEB_INCLUDE_MODULEWEB_CONSTANT_INFO_H
