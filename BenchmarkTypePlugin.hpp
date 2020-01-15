

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from BenchmarkType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef BenchmarkTypePlugin_223200961_h
#define BenchmarkTypePlugin_223200961_h

#include "BenchmarkType.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif
#ifndef metp_type_plugin_h
#include "metp/metp_type_plugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define BenchmarkMessageTypePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

RTIBool BenchmarkMessageTypePlugin_get_buffer_w_params(
    PRESTypePluginEndpointData endpointData,
    struct REDABuffer *buffer,
    const void *user_data,
    const struct NDDS_WriterHistory_AllocatorParams *allocatorParams);

void BenchmarkMessageTypePlugin_return_buffer_w_params(
    PRESTypePluginEndpointData endpointData,
    struct REDABuffer *buffer,
    const struct NDDS_WriterHistory_AllocatorParams *allocatorParams);

#define BenchmarkMessageTypePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define BenchmarkMessageTypePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern BenchmarkMessageType*
BenchmarkMessageTypePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern BenchmarkMessageType*
BenchmarkMessageTypePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern BenchmarkMessageType*
BenchmarkMessageTypePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePluginSupport_copy_data(
    BenchmarkMessageType *out,
    const BenchmarkMessageType *in);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePluginSupport_destroy_data_w_params(
    BenchmarkMessageType *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePluginSupport_destroy_data_ex(
    BenchmarkMessageType *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePluginSupport_destroy_data(
    BenchmarkMessageType *sample);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePluginSupport_print_data(
    const BenchmarkMessageType *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
BenchmarkMessageTypePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
BenchmarkMessageTypePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
BenchmarkMessageTypePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType *out,
    const BenchmarkMessageType *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageType *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
BenchmarkMessageTypePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const BenchmarkMessageType *sample,
    dds::core::policy::DataRepresentationId representation
    = dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
BenchmarkMessageTypePlugin_deserialize_from_cdr_buffer(
    BenchmarkMessageType *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
BenchmarkMessageTypePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);   

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
BenchmarkMessageTypePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const BenchmarkMessageType * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
BenchmarkMessageTypePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageType *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
BenchmarkMessageTypePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
BenchmarkMessageTypePlugin_new(void);

NDDSUSERDllExport extern void
BenchmarkMessageTypePlugin_delete(struct PRESTypePlugin *);

#define BenchmarkMessageTypePlainHelperPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define BenchmarkMessageTypePlainHelperPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define BenchmarkMessageTypePlainHelperPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define BenchmarkMessageTypePlainHelperPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define BenchmarkMessageTypePlainHelperPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern BenchmarkMessageTypePlainHelper*
BenchmarkMessageTypePlainHelperPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern BenchmarkMessageTypePlainHelper*
BenchmarkMessageTypePlainHelperPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern BenchmarkMessageTypePlainHelper*
BenchmarkMessageTypePlainHelperPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlainHelperPluginSupport_copy_data(
    BenchmarkMessageTypePlainHelper *out,
    const BenchmarkMessageTypePlainHelper *in);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePlainHelperPluginSupport_destroy_data_w_params(
    BenchmarkMessageTypePlainHelper *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePlainHelperPluginSupport_destroy_data_ex(
    BenchmarkMessageTypePlainHelper *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePlainHelperPluginSupport_destroy_data(
    BenchmarkMessageTypePlainHelper *sample);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePlainHelperPluginSupport_print_data(
    const BenchmarkMessageTypePlainHelper *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
BenchmarkMessageTypePlainHelperPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePlainHelperPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
BenchmarkMessageTypePlainHelperPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
BenchmarkMessageTypePlainHelperPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
BenchmarkMessageTypePlainHelperPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlainHelperPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper *out,
    const BenchmarkMessageTypePlainHelper *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlainHelperPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageTypePlainHelper *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlainHelperPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
BenchmarkMessageTypePlainHelperPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const BenchmarkMessageTypePlainHelper *sample,
    dds::core::policy::DataRepresentationId representation
    = dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlainHelperPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
BenchmarkMessageTypePlainHelperPlugin_deserialize_from_cdr_buffer(
    BenchmarkMessageTypePlainHelper *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
BenchmarkMessageTypePlainHelperPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);   

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const BenchmarkMessageTypePlainHelper * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
BenchmarkMessageTypePlainHelperPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlainHelperPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageTypePlainHelper *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlainHelperPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
BenchmarkMessageTypePlainHelperPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
BenchmarkMessageTypePlainHelperPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
BenchmarkMessageTypePlainHelperPlugin_new(void);

NDDSUSERDllExport extern void
BenchmarkMessageTypePlainHelperPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* BenchmarkTypePlugin_223200961_h */

