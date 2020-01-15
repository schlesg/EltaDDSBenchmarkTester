

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from BenchmarkType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <string.h>

#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "dds_c/dds_c_typecode_impl.h"

#include "rti/topic/cdr/Serialization.hpp"

#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include "BenchmarkTypePlugin.hpp"

/* ----------------------------------------------------------------------------
*  Type BenchmarkMessageType
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

BenchmarkMessageType *
BenchmarkMessageTypePluginSupport_create_data(void)
{
    return BenchmarkMessageType::create_data();
}

void 
BenchmarkMessageTypePluginSupport_destroy_data(
    BenchmarkMessageType *sample) 
{
    BenchmarkMessageType::delete_data(sample);
}

RTIBool 
BenchmarkMessageTypePluginSupport_copy_data(
    BenchmarkMessageType *dst,
    const BenchmarkMessageType *src)
{
    RTIOsapiUtility_unusedParameter(dst);
    RTIOsapiUtility_unusedParameter(src);

    return RTI_FALSE;
}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

BenchmarkMessageType*
BenchmarkMessageTypePlugin_create_metp_data(void)
{
    return (BenchmarkMessageType*)PRES_TYPE_PLUGIN_INVALID_SAMPLE_ADDRESS;
}

void
BenchmarkMessageTypePlugin_destroy_metp_data(void* )
{
}

RTI_UINT32
BenchmarkMessageTypePlugin_get_deserialized_sample_max_size(
    PRESTypePluginEndpointData epd)
{
    RTIOsapiUtility_unusedParameter(epd);
    return RTI_XCDR_ENCAPSULATION_HEADER_SIZE
    + static_cast<RTI_UINT32>(RTIOsapiAlignment_alignSizeUp(
        BenchmarkMessageTypeOffset::serialized_size(0),
        MIG_RTPS_SUBMESSAGE_ALIGNMENT));
}

RTIBool BenchmarkMessageTypePlugin_get_buffer_w_params(
    PRESTypePluginEndpointData endpointData,
    struct REDABuffer *buffer,
    const void *user_data,
    const struct NDDS_WriterHistory_AllocatorParams *allocatorParams)
{
    if (allocatorParams->encapsulationId == DDS_ENCAPSULATION_ID_SHMEM_REF_FLAT_DATA) {
        return PRESTypePluginDefaultEndpointData_getBuffer(
            endpointData, buffer, allocatorParams->encapsulationId, user_data);
    } else {
        if ((allocatorParams->sampleKind == NDDS_WRITERHISTORY_DATA_SAMPLE) 
        && !PRESTypePluginDefaultEndpointData_isSecurityEnabled(endpointData)) {
            buffer->pointer = (char *) user_data; // FLAT_DATA: the sample is the buffer
            buffer->length = static_cast<int>(RTIOsapiAlignment_alignSizeUp(
                BenchmarkMessageTypeOffset::serialized_size(0),
                MIG_RTPS_SUBMESSAGE_ALIGNMENT)) 
                + RTI_XCDR_ENCAPSULATION_HEADER_SIZE;
            return RTI_TRUE;
        } else {
            return PRESTypePluginDefaultEndpointData_getBuffer(
                endpointData, buffer, allocatorParams->encapsulationId, user_data);
        }
    }
}

void BenchmarkMessageTypePlugin_return_buffer_w_params(
    PRESTypePluginEndpointData endpointData,
    struct REDABuffer *buffer,
    const struct NDDS_WriterHistory_AllocatorParams *allocatorParams)
{
    if (allocatorParams->encapsulationId == DDS_ENCAPSULATION_ID_SHMEM_REF_FLAT_DATA) {
        return PRESTypePluginDefaultEndpointData_returnBuffer(
            endpointData, buffer, allocatorParams->encapsulationId);
    }
    if ((allocatorParams->sampleKind != NDDS_WRITERHISTORY_DATA_SAMPLE)
    || PRESTypePluginDefaultEndpointData_isSecurityEnabled(endpointData)) {
        return PRESTypePluginDefaultEndpointData_returnBuffer(
            endpointData, buffer, allocatorParams->encapsulationId);
    }

    // FLAT_DATA : nothing to do for NDDS_WRITERHISTORY_DATA_SAMPLE
}

BenchmarkMessageType*
BenchmarkMessageTypePlugin_create_flat_data_sentinel(void)
{
    return (BenchmarkMessageType*)PRES_TYPE_PLUGIN_INVALID_SAMPLE_ADDRESS;
}

void
BenchmarkMessageTypePlugin_destroy_flat_data_sentinel(void* sample)
{
    RTIOsapiUtility_unusedParameter(sample);
}

void*
BenchmarkMessageTypePlugin_get_sample_flat_data(
    PRESTypePluginEndpointData endpointData,
    void **handle)
{
    return PRESTypePluginDefaultEndpointData_getSample(endpointData,handle);
}

void
BenchmarkMessageTypePlugin_return_sample_flat_data(
    PRESTypePluginEndpointData endpointData,
    void *sample, 
    void *handle)
{
    struct REDAFastBufferPool *pool = PRESTypePluginDefaultEndpointData_getFstSampleDataPool(endpointData);
    if (pool && (sample != reinterpret_cast<void *>(PRES_TYPE_PLUGIN_INVALID_SAMPLE_ADDRESS))) {
        REDAFastBufferPool_returnBuffer(pool, sample);
        if (handle != NULL) {
            *static_cast<void**>(handle) =
            reinterpret_cast<void *>(PRES_TYPE_PLUGIN_INVALID_SAMPLE_ADDRESS);
        }
    }
    if (handle != NULL) {
        PRESTypePluginDefaultEndpointData_returnSample(endpointData,sample,handle);
    }
}

PRESTypePluginParticipantData 
BenchmarkMessageTypePlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    struct PRESTypePluginDefaultParticipantData *pd = NULL;
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
    pd = (struct PRESTypePluginDefaultParticipantData *)
    PRESTypePluginDefaultParticipantData_new(participant_info);

    programProperty.generateV1Encapsulation = RTI_XCDR_FALSE;
    programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_TRUE;
    programProperty.optimizeEnum = RTI_XCDR_TRUE;

    programProperty.externalReferenceSize = 
    (RTIXCdrUnsignedShort) sizeof(dds::core::external<char>);
    programProperty.getExternalRefPointerFcn = 
    rti::topic::interpreter::get_external_value_pointer;

    programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
        DDS_TypeCodeFactory_get_instance(),
        (DDS_TypeCode *)&rti::topic::dynamic_type<BenchmarkMessageTypePlainHelper>::get().native(),
        &programProperty,
        RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);

    if (programs == NULL) {
        PRESTypePluginDefaultParticipantData_delete(
            (PRESTypePluginParticipantData)pd);
        return NULL;
    }

    pd->programs = programs;
    return METypePlugin_on_participant_attached(
        pd,
        registration_data,
        participant_info,
        top_level_registration,
        container_plugin_context,
        type_code);
}

void 
BenchmarkMessageTypePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{
    if (participant_data != NULL) {
        struct PRESTypePluginDefaultParticipantData *pd = 
        (struct PRESTypePluginDefaultParticipantData *)participant_data;

        if (pd->programs != NULL) {
            DDS_TypeCodeFactory_remove_programs_from_global_list(
                DDS_TypeCodeFactory_get_instance(),
                pd->programs);
            pd->programs = NULL;
        }
        METypePlugin_on_participant_detached(participant_data);
        PRESTypePluginDefaultParticipantData_delete(participant_data);
    }
}

PRESTypePluginEndpointData
BenchmarkMessageTypePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    try {
        PRESTypePluginEndpointData epd = NULL;
        void *plugin = NULL;
        unsigned int serializedSampleMaxSize = 0;

        if (participant_data == NULL) {
            return NULL;
        } 

        if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
            plugin = DDS_Entity_get_reserved_dataI(
                DDS_DataWriter_as_entity(endpoint_info->reserved));
        } else {
            plugin = DDS_Entity_get_reserved_dataI(
                DDS_DataReader_as_entity(endpoint_info->reserved));
        }
        if (plugin != NULL) {
            epd = PRESTypePluginDefaultEndpointData_new(
                participant_data,
                endpoint_info,
                (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
                BenchmarkMessageTypePlugin_create_metp_data,
                (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
                BenchmarkMessageTypePlugin_destroy_metp_data,
                NULL, NULL);
        } else {
            epd = PRESTypePluginDefaultEndpointData_new(
                participant_data,
                endpoint_info,
                (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
                BenchmarkMessageTypePluginSupport_create_data,
                (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
                BenchmarkMessageTypePluginSupport_destroy_data,
                NULL , NULL );
        }

        if (epd == NULL) {
            return NULL;
        } 

        serializedSampleMaxSize = BenchmarkMessageTypePlugin_get_serialized_sample_max_size(
            epd,RTI_TRUE,RTI_XCDR_ENCAPSULATION_ID_PL_CDR2_BE,0);

        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);   

        if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {

            if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
                (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                BenchmarkMessageTypePlugin_get_serialized_sample_max_size, epd,
                (PRESTypePluginGetSerializedSampleSizeFunction)
                BenchmarkMessageTypePlugin_get_serialized_sample_size,
                epd) == RTI_FALSE) {
                PRESTypePluginDefaultEndpointData_delete(epd);
                return NULL;
            }
        }
        if (!METypePlugin_on_endpoint_attached(
            participant_data,
            epd,
            endpoint_info,
            top_level_registration,
            containerPluginContext,
            BenchmarkMessageTypePlugin_get_deserialized_sample_max_size(epd),
            dds::topic::topic_type_support<BenchmarkMessageType>::native_initialize_sample)) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }

        return epd;
    } catch (...) {
        return NULL;
    }
}

void 
BenchmarkMessageTypePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  
    METypePlugin_on_endpoint_detached(endpoint_data);
    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
BenchmarkMessageTypePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType *sample,
    void *handle)
{
    try {
        rti::topic::reset_sample(*sample);
    } catch(const std::exception& ex) {
        RTICdrLog_exception(
            "BenchmarkMessageTypePlugin_return_sample",
            &RTI_LOG_ANY_FAILURE_s,
            "exception: ",
            ex.what());           
    }

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
BenchmarkMessageTypePlugin_copy_sample(
    PRESTypePluginEndpointData,
    BenchmarkMessageType *dst,
    const BenchmarkMessageType *src)
{
    return BenchmarkMessageTypePluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
BenchmarkMessageTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
BenchmarkMessageTypePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageType *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    RTIBool retval = RTI_TRUE;
    RTIBool metp = RTI_FALSE;
    char * rti_position = NULL;
    RTIBool serialize_encapsulation_requested = serialize_encapsulation;

    if(serialize_encapsulation) {
        if (!METypePlugin_serializeAndSetCdrEncapsulation(
            endpoint_data,stream,encapsulation_id,&metp)) {
            return RTI_FALSE;
        }
        rti_position = RTICdrStream_resetAlignment(stream);
    }
    if(metp && serialize_sample) {
        if (!METypePlugin_serialize(
            endpoint_data,
            sample,
            stream,
            serialize_encapsulation,
            encapsulation_id,
            serialize_sample,
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
        return RTI_TRUE; 
    } else if (!metp && METypePlugin_cdrEnabled(endpoint_data) && serialize_sample) {
        serialize_encapsulation = RTI_FALSE;
        RTIXCdrStream *xcdrStream = RTICdrStream_asXCdrStream(stream);
        RTIXCdrUnsignedLong sampleSize = 0;

        RTIOsapiUtility_unusedParameter(endpoint_data);
        RTIOsapiUtility_unusedParameter(endpoint_plugin_qos);

        if (RTIXCdrFlatSample_getEncapsulation(
            reinterpret_cast<const char *>(sample)) != encapsulation_id) {
            return RTI_FALSE;
        }

        if (serialize_sample) {
            sampleSize = BenchmarkMessageTypeOffset::serialized_size(0);
            if (reinterpret_cast<const char *>(sample) != RTIXCdrStream_getBuffer(xcdrStream)) {
                if (!RTIXCdrStream_serializeNByte(
                    xcdrStream,
                    sample + RTI_XCDR_ENCAPSULATION_HEADER_SIZE,
                    1,
                    sampleSize)) {
                    return RTI_FALSE;
                }
            } else {
                if (!RTIXCdrStream_skipNByte(
                    xcdrStream,
                    1,
                    sampleSize)) {
                    return RTI_FALSE;
                }
            }
        }

    } else if (serialize_sample) {
        return RTI_FALSE;
    }
    if (serialize_encapsulation_requested) {
        RTICdrStream_restoreAlignment(stream,rti_position);
    }
    return retval;

}

RTIBool 
BenchmarkMessageTypePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    RTIOsapiUtility_unusedParameter(endpoint_data);
    RTIOsapiUtility_unusedParameter(sample);
    RTIOsapiUtility_unusedParameter(stream);
    RTIOsapiUtility_unusedParameter(deserialize_encapsulation);
    RTIOsapiUtility_unusedParameter(deserialize_sample);
    RTIOsapiUtility_unusedParameter(endpoint_plugin_qos);

    return RTI_FALSE;

}

RTIBool
BenchmarkMessageTypePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const BenchmarkMessageType *sample,
    dds::core::policy::DataRepresentationId representation)
{
    if (representation == dds::core::policy::DataRepresentation::xcdr()) {
        // Flat Data only supports XCDR2
        RTICdrLog_exception(
            "BenchmarkMessageTypePlugin_serialize_to_cdr_buffer", 
            &RTI_CDR_LOG_SERIALIZE_FAILURE_s, 
            "representation id parameter must be XCDR2");        
        return RTI_FALSE;
    }
    if (length == NULL) {
        return RTI_FALSE;
    }

    const unsigned int serialized_size = static_cast<unsigned int>(
        sample->buffer_size());

    if (buffer == NULL) {
        *length = serialized_size;
        return RTI_TRUE;
    }

    if (*length < serialized_size) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_copy(buffer, sample->get_buffer(), serialized_size);

    return RTI_TRUE;
}

RTIBool
BenchmarkMessageTypePlugin_deserialize_from_cdr_buffer(
    BenchmarkMessageType *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultParticipantData pd;
    struct RTIXCdrTypePluginProgramContext defaultProgramConext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePlugin plugin;
    struct PRESTypePluginDefaultEndpointData epd;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    epd.programContext = defaultProgramConext;  
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    plugin.typeCode = (struct RTICdrTypeCode *)
    (struct RTICdrTypeCode *)(RTIXCdrTypeCode *)&rti::topic::dynamic_type<BenchmarkMessageType>::get().native()
    ;
    pd.programs = rti::topic::interpreter::get_cdr_serialization_programs<
    BenchmarkMessageType, 
    true, true, true>();

    epd._assignabilityProperty.acceptUnknownEnumValue = RTI_XCDR_TRUE;
    epd._assignabilityProperty.acceptUnknownUnionDiscriminator = RTI_XCDR_TRUE;

    rti::topic::reset_sample(*sample);
    return BenchmarkMessageTypePlugin_deserialize_sample( 
        (PRESTypePluginEndpointData)&epd,
        sample,
        &stream, 
        RTI_TRUE, 
        RTI_TRUE, 
        NULL);
}

RTIBool 
BenchmarkMessageTypePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result = RTI_FALSE;
        RTIBool metp = RTI_FALSE;
        char * rti_position = NULL;
        RTIBool deserialize_encapsulation_requested = deserialize_encapsulation;
        const char *METHOD_NAME = "BenchmarkMessageTypePlugin_deserialize";
        if (drop_sample) {} /* To avoid warnings */

        stream->_xTypesState.unassignable = RTI_FALSE;

        if (deserialize_encapsulation) {
            if (!METypePlugin_deserializeAndSetCdrEncapsulation(
                endpoint_data, stream, &metp)) {
                return RTI_FALSE;
            }

            rti_position = RTICdrStream_resetAlignment(stream);
        }
        else {
            if (RTICdrEncapsulation_validShmemRefEncapsulationId(
                RTICdrStream_getEncapsulationKind(stream))) {
                metp = RTI_TRUE;
            }
        }
        deserialize_encapsulation = RTI_FALSE;
        if (metp && deserialize_sample) {
            result = METypePlugin_deserialize(
                endpoint_data,
                (void**)sample,
                drop_sample,
                stream,
                deserialize_encapsulation,
                deserialize_sample,
                endpoint_plugin_qos);
        } else if (!metp && METypePlugin_cdrEnabled(endpoint_data)
        && deserialize_sample) {
            if (*sample == (void*)PRES_TYPE_PLUGIN_INVALID_SAMPLE_ADDRESS) {
                *sample = (BenchmarkMessageType *)
                METypePlugin_get_sample(endpoint_data);
                RTIXCdrFlatSample_initializeEncapsulation(
                    *(char **)sample,
                    RTICdrStream_getEncapsulationKind(stream));
            }
            RTIXCdrStream *xcdrStream = RTICdrStream_asXCdrStream(stream);
            RTIXCdrUnsignedLong sampleSize = 0;

            RTIOsapiUtility_unusedParameter(endpoint_plugin_qos);

            if (deserialize_encapsulation) {
                if (!RTIXCdrStream_deserializeAndSetCdrEncapsulation(xcdrStream)) {
                    return RTI_FALSE;
                }
            }

            if (deserialize_sample) {
                sampleSize = BenchmarkMessageTypeOffset::serialized_size(0);
                if (*reinterpret_cast<void **>(sample) == reinterpret_cast<void *>(
                    PRES_TYPE_PLUGIN_INVALID_SAMPLE_ADDRESS)) {
                    *sample = reinterpret_cast<BenchmarkMessageType *>(PRESTypePluginDefaultEndpointData_getFstSampleWithSize(
                        endpoint_data, 
                        sampleSize + RTI_XCDR_ENCAPSULATION_HEADER_SIZE));
                    RTIXCdrFlatSample_initializeEncapsulation(
                        *reinterpret_cast<char **>(sample),
                        RTIXCdrStream_getEncapsulationId(xcdrStream));            
                } else if (RTIXCdrFlatSample_getEncapsulation(
                    *reinterpret_cast<char **>(sample)) !=
                    RTIXCdrStream_getEncapsulationId(xcdrStream)) {
                    return RTI_FALSE;
                }

                if (*reinterpret_cast<char **>(sample) != RTIXCdrStream_getBuffer(xcdrStream)) {
                    if (!RTIXCdrStream_deserializeNByte(
                        xcdrStream,
                        *reinterpret_cast<char **>(sample) 
                        + RTI_XCDR_ENCAPSULATION_HEADER_SIZE,
                        1,
                        sampleSize)) {
                        return RTI_FALSE;
                    }
                } else {
                    if (!RTIXCdrStream_skipNByte(
                        xcdrStream,
                        1,
                        sampleSize)) {
                        return RTI_FALSE;
                    }    
                }
            }
            result = RTI_TRUE;
            if (result) {
                if (stream->_xTypesState.unassignable) {
                    result = RTI_FALSE;
                }
            }
            if (!result && stream->_xTypesState.unassignable ) {

                RTICdrLog_exception(
                    METHOD_NAME, 
                    &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
                    "BenchmarkMessageType");

            }
        } else if (deserialize_sample) {
            *drop_sample = RTI_TRUE;
            result = RTI_TRUE;    	
        } else {
            result = RTI_TRUE;
        }
        if (deserialize_encapsulation_requested) {
            RTICdrStream_restoreAlignment(stream,rti_position);
        }
        return result;

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool BenchmarkMessageTypePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSkip(
        endpoint_data,
        stream,   
        skip_encapsulation,
        skip_sample, 
        endpoint_plugin_qos);
}

unsigned int 
BenchmarkMessageTypePlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool *overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    RTIBool metp = RTI_FALSE;
    RTIOsapiUtility_unusedParameter(overflow);
    unsigned int initial_alignment = current_alignment;
    unsigned int encapsulation_size = current_alignment;

    if (include_encapsulation) {
        if (!METypePlugin_validEncapsulationId(encapsulation_id) && 
        !RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += METypePlugin_get_serialized_sample_max_size(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment,
        &metp);
    if (!metp) {
        RTIOsapiUtility_unusedParameter(endpoint_data);
        RTIOsapiUtility_unusedParameter(encapsulation_id);
        RTIOsapiUtility_unusedParameter(current_alignment);

        if (include_encapsulation) {
            return static_cast<unsigned int>(
                BenchmarkMessageTypeOffset::serialized_size(current_alignment) +
                RTI_XCDR_ENCAPSULATION_HEADER_SIZE);
        } else {
            return static_cast<unsigned int>(
                BenchmarkMessageTypeOffset::serialized_size(current_alignment));
        }
    }
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;

}

unsigned int 
BenchmarkMessageTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = BenchmarkMessageTypePlugin_get_serialized_sample_max_size_ex(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return 0;
    }    
}

unsigned int 
BenchmarkMessageTypePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    RTIBool metp = RTI_FALSE;
    unsigned int initial_alignment = current_alignment;
    unsigned int encapsulation_size = current_alignment;

    if (include_encapsulation) {
        if (!METypePlugin_validEncapsulationId(encapsulation_id) && 
        !RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += METypePlugin_get_serialized_sample_min_size(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment,
        &metp);
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    if (metp) {
        return current_alignment - initial_alignment;
    } else {
        current_alignment = initial_alignment; 
        return PRESTypePlugin_interpretedGetSerializedSampleMinSize(
            endpoint_data,
            include_encapsulation,
            encapsulation_id,
            current_alignment);
    }

}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
BenchmarkMessageTypePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const BenchmarkMessageType * sample) 
{
    RTIBool metp = RTI_FALSE;
    unsigned int encapsulation_size = current_alignment;
    unsigned int initial_alignment = current_alignment;

    if (include_encapsulation) {
        if (!METypePlugin_validEncapsulationId(encapsulation_id) && 
        !RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);
    }

    current_alignment += METypePlugin_get_serialized_sample_size(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment,
        &metp);
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }    
    if (metp) {
        return current_alignment - initial_alignment;
    } else {
        current_alignment = initial_alignment;
        RTIOsapiUtility_unusedParameter(sample);
        RTIOsapiUtility_unusedParameter(endpoint_data);
        RTIOsapiUtility_unusedParameter(encapsulation_id);
        RTIOsapiUtility_unusedParameter(current_alignment);

        if (include_encapsulation) {
            return static_cast<unsigned int>(
                BenchmarkMessageTypeOffset::serialized_size(current_alignment) +
                RTI_XCDR_ENCAPSULATION_HEADER_SIZE);
        } else {
            return static_cast<unsigned int>(
                BenchmarkMessageTypeOffset::serialized_size(current_alignment));
        }
        return PRESTypePlugin_interpretedGetSerializedSampleSize(
            endpoint_data,
            include_encapsulation,
            encapsulation_id,
            current_alignment,
            sample);
    }

}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
BenchmarkMessageTypePlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_NO_KEY;
}

RTIBool 
BenchmarkMessageTypePlugin_serialize_key_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageType *sample, 
    struct RTICdrStream *stream,    
    RTIEncapsulationId encapsulation_id,
    void *endpoint_plugin_qos)
{
    RTIBool result = RTI_FALSE;
    RTIXCdrUnsignedLong sampleSize = 0;
    BenchmarkMessageTypePlainHelper *plainSample =
    reinterpret_cast<BenchmarkMessageTypePlainHelper *>(
        PRESTypePluginDefaultEndpointData_getPlainHelperSample(endpoint_data));
    if (plainSample == NULL) {
        return RTI_FALSE;
    }

    sampleSize = static_cast<unsigned int>(
        BenchmarkMessageTypeOffset::serialized_size(0) +
        RTI_XCDR_ENCAPSULATION_HEADER_SIZE);
    if (BenchmarkMessageTypePlainHelperPlugin_deserialize_from_cdr_buffer(
        plainSample,
        (const char *)sample,
        sampleSize)) {
        result = PRESTypePlugin_interpretedSerializeKeyForKeyhash(
            endpoint_data,
            plainSample,
            stream,
            encapsulation_id,
            endpoint_plugin_qos);
    }

    return result;
}

RTIBool 
BenchmarkMessageTypePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageType *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    if (METypePlugin_validShmemEncapsulationId(encapsulation_id)) {
        encapsulation_id = DDS_DataRepresentationQosPolicy_getNativeEncapsulation(
            METypePlugin_getDataRepresentationId(endpoint_data));
    }
    RTIBool result = RTI_FALSE;
    RTIXCdrUnsignedLong sampleSize = 0;
    struct RTICdrStream tempStream;
    BenchmarkMessageTypePlainHelper *plainSample =
    reinterpret_cast<BenchmarkMessageTypePlainHelper *>(
        PRESTypePluginDefaultEndpointData_getPlainHelperSample(endpoint_data));
    if (plainSample == NULL) {
        return RTI_FALSE;
    }

    sampleSize = static_cast<unsigned int>(
        BenchmarkMessageTypeOffset::serialized_size(0) +
        RTI_XCDR_ENCAPSULATION_HEADER_SIZE);
    RTICdrStream_init(&tempStream);
    RTICdrStream_set(&tempStream, (char *)sample, sampleSize);
    if (PRESTypePlugin_interpretedSerializedSampleToKey(
        endpoint_data,
        plainSample,
        &tempStream,
        RTI_TRUE,
        RTI_TRUE,
        endpoint_plugin_qos)) {
        result = PRESTypePlugin_interpretedSerializeKey(
            endpoint_data,
            plainSample,
            stream,
            serialize_encapsulation,
            encapsulation_id,
            serialize_key,
            endpoint_plugin_qos);
    }

    return result;

}

RTIBool BenchmarkMessageTypePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result = RTI_FALSE;
    BenchmarkMessageTypePlainHelper *plainSample = 
    reinterpret_cast<BenchmarkMessageTypePlainHelper *>(
        PRESTypePluginDefaultEndpointData_getPlainHelperSample(endpoint_data));
    if (plainSample == NULL) {
        return RTI_FALSE;
    }
    if (!PRESTypePlugin_interpretedDeserializeKey(
        endpoint_data,
        plainSample,
        stream,
        deserialize_encapsulation,
        deserialize_key,
        endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
    unsigned int length = PRESTypePluginDefaultEndpointData_getMaxSizeSerializedSample(
        endpoint_data);
    result = BenchmarkMessageTypePlainHelperPlugin_serialize_to_cdr_buffer(
        (char *)sample,
        &length,
        plainSample,
        DDS_XCDR2_DATA_REPRESENTATION);

    return result;

}

RTIBool BenchmarkMessageTypePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result;
        void* return_loaned_buffer = 
        (*reinterpret_cast<char **>(sample) == RTICdrStream_getBuffer(stream)) ? 
        *reinterpret_cast<void **>(sample) : NULL;        
        if (drop_sample) {} /* To avoid warnings */
        stream->_xTypesState.unassignable = RTI_FALSE;
        if (deserialize_key) {
            *sample = (BenchmarkMessageType *)
            METypePlugin_get_sample(endpoint_data);
        }
        if (deserialize_encapsulation && deserialize_key) {
            RTIOsapiMemory_copy(
                *sample,
                RTICdrStream_getBuffer(stream),
                RTI_XCDR_ENCAPSULATION_HEADER_SIZE);
        } else if (deserialize_key) {
            RTIXCdrFlatSample_initializeEncapsulation(
                *reinterpret_cast<char **>(sample),
                RTICdrStream_getEncapsulationKind(stream));    
        }
        result= BenchmarkMessageTypePlugin_deserialize_key_sample( 
            endpoint_data, (sample != NULL)?*sample:NULL, stream,
            deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
        if (result) {
            if (stream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }
        if (return_loaned_buffer != NULL) {
            REDAFastBufferPool_returnBuffer(
                PRESTypePluginDefaultEndpointData_getFstSampleDataPool(
                    endpoint_data),
                    RTICdrStream_getBuffer(stream));  
        }        
        return result;    
    } catch (...) {
        return RTI_FALSE;
    }     
}

unsigned int
BenchmarkMessageTypePlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
        endpoint_data,
        overflow,
        include_encapsulation,
        encapsulation_id,
        current_alignment);

}

unsigned int
BenchmarkMessageTypePlugin_get_serialized_key_max_size_for_keyhash_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
        endpoint_data,
        overflow,
        encapsulation_id,
        current_alignment);
}

unsigned int
BenchmarkMessageTypePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        if (METypePlugin_validShmemEncapsulationId(encapsulation_id)) {
            encapsulation_id = DDS_DataRepresentationQosPolicy_getNativeEncapsulation(
                METypePlugin_getDataRepresentationId(endpoint_data));
        }
        size = PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return RTI_FALSE;
    }    
}

unsigned int
BenchmarkMessageTypePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
        endpoint_data,
        &overflow,
        encapsulation_id,
        current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
BenchmarkMessageTypePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageType *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializedSampleToKey(
        endpoint_data,
        sample,
        stream, 
        deserialize_encapsulation,  
        deserialize_key, 
        endpoint_plugin_qos);

}

void*
BenchmarkMessageTypePlugin_get_sample_metp(
    PRESTypePluginEndpointData endpointData,
    void **handle)
{
    return PRESTypePluginDefaultEndpointData_getSample(endpointData, handle);
}

void
BenchmarkMessageTypePlugin_return_sample_metp(
    PRESTypePluginEndpointData endpointData,
    void *sample, 
    void *handle)
{
    if ((handle != NULL)
    && (*reinterpret_cast<void **>(handle)
    == reinterpret_cast<void *>(PRES_TYPE_PLUGIN_INVALID_REASSEMBLED_SAMPLE_ADDRESS))) {
        BenchmarkMessageTypePlugin_return_sample_flat_data(
            endpointData, sample, handle);
    } else {
        METypePlugin_return_sample(endpointData, sample, handle);
        /*
        * A NULL handle indicates that the sample did not come from the 
        * TypePlugin sample pool. Hence we do not return it to the pool.
        */
        if (handle != NULL) {
            PRESTypePluginDefaultEndpointData_returnSample(
                endpointData,
                sample,
                handle);
        }
    }
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *BenchmarkMessageTypePlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    BenchmarkMessageTypePlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    BenchmarkMessageTypePlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    BenchmarkMessageTypePlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    BenchmarkMessageTypePlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    BenchmarkMessageTypePlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    BenchmarkMessageTypePlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    BenchmarkMessageTypePlugin_destroy_sample;

    plugin->serializeFnc = 
    (PRESTypePluginSerializeFunction) BenchmarkMessageTypePlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction) BenchmarkMessageTypePlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    BenchmarkMessageTypePlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    BenchmarkMessageTypePlugin_get_serialized_sample_min_size;
    plugin->getDeserializedSampleMaxSizeFnc = 
    (PRESTypePluginGetDeserializedSampleMaxSizeFunction)
    BenchmarkMessageTypePlugin_get_deserialized_sample_max_size;
    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    BenchmarkMessageTypePlugin_get_sample_metp;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    BenchmarkMessageTypePlugin_return_sample_metp;
    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    BenchmarkMessageTypePlugin_get_key_kind;

    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL ;    
    plugin->deserializeKeyFnc = NULL;  
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;    
    #ifdef NDDS_STANDALONE_TYPE
    plugin->typeCode = NULL; 
    #else
    plugin->typeCode = (struct RTICdrTypeCode *) 
    &rti::topic::dynamic_type<BenchmarkMessageType>::get().native();
    #endif
    plugin->languageKind = PRES_TYPEPLUGIN_FLATDATA_TYPE;

    /* Serialized buffer */
    plugin->getBufferWithParams = 
    (NDDS_WriterHistory_Allocator_getBufferWithParams_fn)
    BenchmarkMessageTypePlugin_get_buffer_w_params;
    plugin->returnBufferWithParams = 
    (NDDS_WriterHistory_Allocator_returnBufferWithParams_fn)
    BenchmarkMessageTypePlugin_return_buffer_w_params;
    plugin->getBuffer = NULL;
    plugin->returnBuffer = NULL;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    BenchmarkMessageTypePlugin_get_serialized_sample_size;

    plugin->getWriterLoanedSampleFnc = NULL; 
    plugin->returnWriterLoanedSampleFnc = NULL;
    plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
    plugin->validateWriterLoanedSampleFnc = NULL;
    plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

    static const char * TYPE_NAME = "BenchmarkMessageType";
    plugin->endpointTypeName = TYPE_NAME;
    plugin->isMetpType = RTI_TRUE;
    return plugin;
}

void
BenchmarkMessageTypePlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* ----------------------------------------------------------------------------
*  Type BenchmarkMessageTypePlainHelper
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

BenchmarkMessageTypePlainHelper *
BenchmarkMessageTypePlainHelperPluginSupport_create_data(void)
{
    try {
        BenchmarkMessageTypePlainHelper *sample = new BenchmarkMessageTypePlainHelper;    
        rti::topic::allocate_sample(*sample);
        return sample;
    } catch (...) {
        return NULL;
    }
}

void 
BenchmarkMessageTypePlainHelperPluginSupport_destroy_data(
    BenchmarkMessageTypePlainHelper *sample) 
{
    delete sample;
}

RTIBool 
BenchmarkMessageTypePlainHelperPluginSupport_copy_data(
    BenchmarkMessageTypePlainHelper *dst,
    const BenchmarkMessageTypePlainHelper *src)
{
    try {
        *dst = *src;
    } catch (...) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

BenchmarkMessageTypePlainHelper*
BenchmarkMessageTypePlainHelperPlugin_create_metp_data(void)
{
    return (BenchmarkMessageTypePlainHelper*)PRES_TYPE_PLUGIN_INVALID_SAMPLE_ADDRESS;
}

void
BenchmarkMessageTypePlainHelperPlugin_destroy_metp_data(void* )
{
}

RTI_UINT32
BenchmarkMessageTypePlainHelperPlugin_get_deserialized_sample_max_size(
    PRESTypePluginEndpointData epd)
{
    RTIOsapiUtility_unusedParameter(epd);
    return static_cast<RTI_UINT32>(sizeof(BenchmarkMessageTypePlainHelper));
}

PRESTypePluginParticipantData 
BenchmarkMessageTypePlainHelperPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    struct PRESTypePluginDefaultParticipantData *pd = NULL;
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
    pd = (struct PRESTypePluginDefaultParticipantData *)
    PRESTypePluginDefaultParticipantData_new(participant_info);

    programProperty.generateV1Encapsulation = RTI_XCDR_FALSE;
    programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_TRUE;
    programProperty.optimizeEnum = RTI_XCDR_TRUE;

    programProperty.externalReferenceSize = 
    (RTIXCdrUnsignedShort) sizeof(dds::core::external<char>);
    programProperty.getExternalRefPointerFcn = 
    rti::topic::interpreter::get_external_value_pointer;

    programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
        DDS_TypeCodeFactory_get_instance(),
        (DDS_TypeCode *) (RTIXCdrTypeCode *)&rti::topic::dynamic_type<BenchmarkMessageTypePlainHelper>::get().native()
        ,
        &programProperty,
        RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);

    if (programs == NULL) {
        PRESTypePluginDefaultParticipantData_delete(
            (PRESTypePluginParticipantData)pd);
        return NULL;
    }

    pd->programs = programs;
    return METypePlugin_on_participant_attached(
        pd,
        registration_data,
        participant_info,
        top_level_registration,
        container_plugin_context,
        type_code);
}

void 
BenchmarkMessageTypePlainHelperPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{
    if (participant_data != NULL) {
        struct PRESTypePluginDefaultParticipantData *pd = 
        (struct PRESTypePluginDefaultParticipantData *)participant_data;

        if (pd->programs != NULL) {
            DDS_TypeCodeFactory_remove_programs_from_global_list(
                DDS_TypeCodeFactory_get_instance(),
                pd->programs);
            pd->programs = NULL;
        }
        METypePlugin_on_participant_detached(participant_data);
        PRESTypePluginDefaultParticipantData_delete(participant_data);
    }
}

PRESTypePluginEndpointData
BenchmarkMessageTypePlainHelperPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    try {
        PRESTypePluginEndpointData epd = NULL;
        void *plugin = NULL;
        unsigned int serializedSampleMaxSize = 0;

        if (participant_data == NULL) {
            return NULL;
        } 

        if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
            plugin = DDS_Entity_get_reserved_dataI(
                DDS_DataWriter_as_entity(endpoint_info->reserved));
        } else {
            plugin = DDS_Entity_get_reserved_dataI(
                DDS_DataReader_as_entity(endpoint_info->reserved));
        }
        if (plugin != NULL) {
            epd = PRESTypePluginDefaultEndpointData_new(
                participant_data,
                endpoint_info,
                (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
                BenchmarkMessageTypePlainHelperPlugin_create_metp_data,
                (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
                BenchmarkMessageTypePlainHelperPlugin_destroy_metp_data,
                NULL, NULL);
        } else {
            epd = PRESTypePluginDefaultEndpointData_new(
                participant_data,
                endpoint_info,
                (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
                BenchmarkMessageTypePlainHelperPluginSupport_create_data,
                (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
                BenchmarkMessageTypePlainHelperPluginSupport_destroy_data,
                NULL , NULL );
        }

        if (epd == NULL) {
            return NULL;
        } 

        if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
            PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

            if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
                (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_max_size, epd,
                (PRESTypePluginGetSerializedSampleSizeFunction)
                BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_size,
                epd) == RTI_FALSE) {
                PRESTypePluginDefaultEndpointData_delete(epd);
                return NULL;
            }
        }
        if (!METypePlugin_on_endpoint_attached(
            participant_data,
            epd,
            endpoint_info,
            top_level_registration,
            containerPluginContext,
            BenchmarkMessageTypePlainHelperPlugin_get_deserialized_sample_max_size(epd),
            dds::topic::topic_type_support<BenchmarkMessageTypePlainHelper>::native_initialize_sample)) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }

        return epd;
    } catch (...) {
        return NULL;
    }
}

void 
BenchmarkMessageTypePlainHelperPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  
    METypePlugin_on_endpoint_detached(endpoint_data);
    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
BenchmarkMessageTypePlainHelperPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper *sample,
    void *handle)
{
    try {
        rti::topic::reset_sample(*sample);
    } catch(const std::exception& ex) {
        RTICdrLog_exception(
            "BenchmarkMessageTypePlainHelperPlugin_return_sample",
            &RTI_LOG_ANY_FAILURE_s,
            "exception: ",
            ex.what());           
    }

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
BenchmarkMessageTypePlainHelperPlugin_copy_sample(
    PRESTypePluginEndpointData,
    BenchmarkMessageTypePlainHelper *dst,
    const BenchmarkMessageTypePlainHelper *src)
{
    return BenchmarkMessageTypePlainHelperPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
BenchmarkMessageTypePlainHelperPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageTypePlainHelper *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    RTIBool retval = RTI_TRUE;
    RTIBool metp = RTI_FALSE;
    char * rti_position = NULL;
    RTIBool serialize_encapsulation_requested = serialize_encapsulation;

    if(serialize_encapsulation) {
        if (!METypePlugin_serializeAndSetCdrEncapsulation(
            endpoint_data,stream,encapsulation_id,&metp)) {
            return RTI_FALSE;
        }
        rti_position = RTICdrStream_resetAlignment(stream);
    }
    if(metp && serialize_sample) {
        if (!METypePlugin_serialize(
            endpoint_data,
            sample,
            stream,
            serialize_encapsulation,
            encapsulation_id,
            serialize_sample,
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
        return RTI_TRUE; 
    } else if (!metp && METypePlugin_cdrEnabled(endpoint_data) && serialize_sample) {
        serialize_encapsulation = RTI_FALSE;
        retval = PRESTypePlugin_interpretedSerialize(
            endpoint_data,
            sample, 
            stream,    
            serialize_encapsulation,
            encapsulation_id,
            serialize_sample, 
            endpoint_plugin_qos);
    } else if (serialize_sample) {
        return RTI_FALSE;
    }
    if (serialize_encapsulation_requested) {
        RTICdrStream_restoreAlignment(stream,rti_position);
    }
    return retval;

}

RTIBool 
BenchmarkMessageTypePlainHelperPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedDeserialize(
        endpoint_data,
        sample,
        stream,   
        deserialize_encapsulation,
        deserialize_sample, 
        endpoint_plugin_qos);

}

RTIBool
BenchmarkMessageTypePlainHelperPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const BenchmarkMessageTypePlainHelper *sample,
    dds::core::policy::DataRepresentationId representation)
{
    using namespace dds::core::policy;

    try{
        RTIEncapsulationId encapsulationId = RTI_CDR_ENCAPSULATION_ID_INVALID;
        struct RTICdrStream stream;
        struct PRESTypePluginDefaultEndpointData epd;
        RTIBool result;
        struct PRESTypePluginDefaultParticipantData pd;
        struct RTIXCdrTypePluginProgramContext defaultProgramConext =
        RTIXCdrTypePluginProgramContext_INTIALIZER;
        struct PRESTypePlugin plugin = PRES_TYPEPLUGIN_DEFAULT;

        if (length == NULL) {
            return RTI_FALSE;
        }

        RTIOsapiMemory_zero(&epd, sizeof(struct PRESTypePluginDefaultEndpointData));
        epd.programContext = defaultProgramConext;  
        epd._participantData = &pd;
        epd.typePlugin = &plugin;
        epd.programContext.endpointPluginData = &epd;
        plugin.typeCode = (struct RTICdrTypeCode *)
        (RTIXCdrTypeCode *)&rti::topic::dynamic_type<BenchmarkMessageTypePlainHelper>::get().native()
        ;
        pd.programs = rti::topic::interpreter::get_cdr_serialization_programs<
        BenchmarkMessageTypePlainHelper, 
        true, true, true>();

        encapsulationId = DDS_TypeCode_get_native_encapsulation(
            (DDS_TypeCode *) plugin.typeCode,
            representation);

        if (encapsulationId == RTI_CDR_ENCAPSULATION_ID_INVALID) {
            return RTI_FALSE;
        }

        epd._maxSizeSerializedSample =
        BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_max_size(
            (PRESTypePluginEndpointData)&epd, 
            RTI_TRUE, 
            encapsulationId,
            0);

        if (buffer == NULL) {
            *length = 
            BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_size(
                (PRESTypePluginEndpointData)&epd,
                RTI_TRUE,
                encapsulationId,
                0,
                sample);

            if (*length == 0) {
                return RTI_FALSE;
            }

            return RTI_TRUE;
        }    

        RTICdrStream_init(&stream);
        RTICdrStream_set(&stream, (char *)buffer, *length);

        result = BenchmarkMessageTypePlainHelperPlugin_serialize(
            (PRESTypePluginEndpointData)&epd, 
            sample, 
            &stream, 
            RTI_TRUE, 
            encapsulationId,
            RTI_TRUE, 
            NULL);  

        *length = RTICdrStream_getCurrentPositionOffset(&stream);
        return result;     
    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool
BenchmarkMessageTypePlainHelperPlugin_deserialize_from_cdr_buffer(
    BenchmarkMessageTypePlainHelper *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultParticipantData pd;
    struct RTIXCdrTypePluginProgramContext defaultProgramConext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePlugin plugin;
    struct PRESTypePluginDefaultEndpointData epd;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    epd.programContext = defaultProgramConext;  
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    plugin.typeCode = (struct RTICdrTypeCode *)
    (struct RTICdrTypeCode *)(RTIXCdrTypeCode *)&rti::topic::dynamic_type<BenchmarkMessageTypePlainHelper>::get().native()
    ;
    pd.programs = rti::topic::interpreter::get_cdr_serialization_programs<
    BenchmarkMessageTypePlainHelper, 
    true, true, true>();

    epd._assignabilityProperty.acceptUnknownEnumValue = RTI_XCDR_TRUE;
    epd._assignabilityProperty.acceptUnknownUnionDiscriminator = RTI_XCDR_TRUE;

    rti::topic::reset_sample(*sample);
    return BenchmarkMessageTypePlainHelperPlugin_deserialize_sample( 
        (PRESTypePluginEndpointData)&epd,
        sample,
        &stream, 
        RTI_TRUE, 
        RTI_TRUE, 
        NULL);
}

RTIBool 
BenchmarkMessageTypePlainHelperPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result = RTI_FALSE;
        RTIBool metp = RTI_FALSE;
        char * rti_position = NULL;
        RTIBool deserialize_encapsulation_requested = deserialize_encapsulation;
        const char *METHOD_NAME = "BenchmarkMessageTypePlainHelperPlugin_deserialize";
        if (drop_sample) {} /* To avoid warnings */

        stream->_xTypesState.unassignable = RTI_FALSE;

        if (deserialize_encapsulation) {
            if (!METypePlugin_deserializeAndSetCdrEncapsulation(
                endpoint_data, stream, &metp)) {
                return RTI_FALSE;
            }

            rti_position = RTICdrStream_resetAlignment(stream);
        }
        else {
            if (RTICdrEncapsulation_validShmemRefEncapsulationId(
                RTICdrStream_getEncapsulationKind(stream))) {
                metp = RTI_TRUE;
            }
        }
        deserialize_encapsulation = RTI_FALSE;
        if (metp && deserialize_sample) {
            result = METypePlugin_deserialize(
                endpoint_data,
                (void**)sample,
                drop_sample,
                stream,
                deserialize_encapsulation,
                deserialize_sample,
                endpoint_plugin_qos);
        } else if (!metp && METypePlugin_cdrEnabled(endpoint_data)
        && deserialize_sample) {
            if (*sample == (void*)PRES_TYPE_PLUGIN_INVALID_SAMPLE_ADDRESS) {
                *sample = (BenchmarkMessageTypePlainHelper *)
                METypePlugin_get_sample(endpoint_data);
            }
            result= BenchmarkMessageTypePlainHelperPlugin_deserialize_sample( 
                endpoint_data, (sample != NULL)?*sample:NULL,
                stream, deserialize_encapsulation, deserialize_sample, 
                endpoint_plugin_qos);
            if (result) {
                if (stream->_xTypesState.unassignable) {
                    result = RTI_FALSE;
                }
            }
            if (!result && stream->_xTypesState.unassignable ) {

                RTICdrLog_exception(
                    METHOD_NAME, 
                    &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
                    "BenchmarkMessageTypePlainHelper");

            }
        } else if (deserialize_sample) {
            *drop_sample = RTI_TRUE;
            result = RTI_TRUE;    	
        } else {
            result = RTI_TRUE;
        }
        if (deserialize_encapsulation_requested) {
            RTICdrStream_restoreAlignment(stream,rti_position);
        }
        return result;

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool BenchmarkMessageTypePlainHelperPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSkip(
        endpoint_data,
        stream,   
        skip_encapsulation,
        skip_sample, 
        endpoint_plugin_qos);
}

unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool *overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    RTIBool metp = RTI_FALSE;
    unsigned int initial_alignment = current_alignment;
    unsigned int encapsulation_size = current_alignment;

    if (include_encapsulation) {
        if (!METypePlugin_validEncapsulationId(encapsulation_id) && 
        !RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += METypePlugin_get_serialized_sample_max_size(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment,
        &metp);
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    if (metp) {
        return current_alignment - initial_alignment;
    } else {
        current_alignment = initial_alignment;
        return PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
            endpoint_data,
            overflow,
            include_encapsulation,
            encapsulation_id,
            current_alignment);
    }

}

unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_max_size_ex(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return 0;
    }    
}

unsigned int 
BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    RTIBool metp = RTI_FALSE;
    unsigned int initial_alignment = current_alignment;
    unsigned int encapsulation_size = current_alignment;

    if (include_encapsulation) {
        if (!METypePlugin_validEncapsulationId(encapsulation_id) && 
        !RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += METypePlugin_get_serialized_sample_min_size(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment,
        &metp);
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    if (metp) {
        return current_alignment - initial_alignment;
    } else {
        current_alignment = initial_alignment; 
        return PRESTypePlugin_interpretedGetSerializedSampleMinSize(
            endpoint_data,
            include_encapsulation,
            encapsulation_id,
            current_alignment);
    }

}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const BenchmarkMessageTypePlainHelper * sample) 
{
    RTIBool metp = RTI_FALSE;
    unsigned int encapsulation_size = current_alignment;
    unsigned int initial_alignment = current_alignment;

    if (include_encapsulation) {
        if (!METypePlugin_validEncapsulationId(encapsulation_id) && 
        !RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);
    }

    current_alignment += METypePlugin_get_serialized_sample_size(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment,
        &metp);
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }    
    if (metp) {
        return current_alignment - initial_alignment;
    } else {
        current_alignment = initial_alignment;
        return PRESTypePlugin_interpretedGetSerializedSampleSize(
            endpoint_data,
            include_encapsulation,
            encapsulation_id,
            current_alignment,
            sample);
    }

}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
BenchmarkMessageTypePlainHelperPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_NO_KEY;
}

RTIBool 
BenchmarkMessageTypePlainHelperPlugin_serialize_key_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageTypePlainHelper *sample, 
    struct RTICdrStream *stream,    
    RTIEncapsulationId encapsulation_id,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializeKeyForKeyhash(
        endpoint_data,
        sample, 
        stream,    
        encapsulation_id,
        endpoint_plugin_qos);
}

RTIBool 
BenchmarkMessageTypePlainHelperPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const BenchmarkMessageTypePlainHelper *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    if (METypePlugin_validShmemEncapsulationId(encapsulation_id)) {
        encapsulation_id = DDS_DataRepresentationQosPolicy_getNativeEncapsulation(
            METypePlugin_getDataRepresentationId(endpoint_data));
    }
    return PRESTypePlugin_interpretedSerializeKey(
        endpoint_data,
        sample, 
        stream,    
        serialize_encapsulation,
        encapsulation_id,
        serialize_key,
        endpoint_plugin_qos);

}

RTIBool BenchmarkMessageTypePlainHelperPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedDeserializeKey(
        endpoint_data,
        sample,
        stream,
        deserialize_encapsulation,
        deserialize_key,
        endpoint_plugin_qos);

}

RTIBool BenchmarkMessageTypePlainHelperPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result;
        if (drop_sample) {} /* To avoid warnings */
        stream->_xTypesState.unassignable = RTI_FALSE;
        if (deserialize_key) {
            *sample = (BenchmarkMessageTypePlainHelper *)
            METypePlugin_get_sample(endpoint_data);
        }
        result= BenchmarkMessageTypePlainHelperPlugin_deserialize_key_sample( 
            endpoint_data, (sample != NULL)?*sample:NULL, stream,
            deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
        if (result) {
            if (stream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }
        return result;    
    } catch (...) {
        return RTI_FALSE;
    }     
}

unsigned int
BenchmarkMessageTypePlainHelperPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
        endpoint_data,
        overflow,
        include_encapsulation,
        encapsulation_id,
        current_alignment);

}

unsigned int
BenchmarkMessageTypePlainHelperPlugin_get_serialized_key_max_size_for_keyhash_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
        endpoint_data,
        overflow,
        encapsulation_id,
        current_alignment);
}

unsigned int
BenchmarkMessageTypePlainHelperPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        if (METypePlugin_validShmemEncapsulationId(encapsulation_id)) {
            encapsulation_id = DDS_DataRepresentationQosPolicy_getNativeEncapsulation(
                METypePlugin_getDataRepresentationId(endpoint_data));
        }
        size = BenchmarkMessageTypePlainHelperPlugin_get_serialized_key_max_size_ex(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return RTI_FALSE;
    }    
}

unsigned int
BenchmarkMessageTypePlainHelperPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = BenchmarkMessageTypePlainHelperPlugin_get_serialized_key_max_size_for_keyhash_ex(
        endpoint_data,
        &overflow,
        encapsulation_id,
        current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
BenchmarkMessageTypePlainHelperPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    BenchmarkMessageTypePlainHelper *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializedSampleToKey(
        endpoint_data,
        sample,
        stream, 
        deserialize_encapsulation,  
        deserialize_key, 
        endpoint_plugin_qos);

}

void*
BenchmarkMessageTypePlainHelperPlugin_get_sample_metp(
    PRESTypePluginEndpointData endpointData,
    void **handle)
{
    return PRESTypePluginDefaultEndpointData_getSample(endpointData, handle);
}

void
BenchmarkMessageTypePlainHelperPlugin_return_sample_metp(
    PRESTypePluginEndpointData endpointData,
    void *sample, 
    void *handle)
{
    METypePlugin_return_sample(endpointData, sample, handle);
    /*
    * A NULL handle indicates that the sample did not come from the 
    * TypePlugin sample pool. Hence we do not return it to the pool.
    */
    if (handle != NULL) {
        PRESTypePluginDefaultEndpointData_returnSample(
            endpointData,
            sample,
            handle);
    }
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *BenchmarkMessageTypePlainHelperPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    BenchmarkMessageTypePlainHelperPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    BenchmarkMessageTypePlainHelperPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    BenchmarkMessageTypePlainHelperPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    BenchmarkMessageTypePlainHelperPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    BenchmarkMessageTypePlainHelperPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    BenchmarkMessageTypePlainHelperPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    BenchmarkMessageTypePlainHelperPlugin_destroy_sample;

    plugin->serializeFnc = 
    (PRESTypePluginSerializeFunction) BenchmarkMessageTypePlainHelperPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction) BenchmarkMessageTypePlainHelperPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_min_size;
    plugin->getDeserializedSampleMaxSizeFnc = 
    (PRESTypePluginGetDeserializedSampleMaxSizeFunction)
    BenchmarkMessageTypePlainHelperPlugin_get_deserialized_sample_max_size;
    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    BenchmarkMessageTypePlainHelperPlugin_get_sample_metp;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    BenchmarkMessageTypePlainHelperPlugin_return_sample_metp;
    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    BenchmarkMessageTypePlainHelperPlugin_get_key_kind;

    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL ;    
    plugin->deserializeKeyFnc = NULL;  
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;    
    #ifdef NDDS_STANDALONE_TYPE
    plugin->typeCode = NULL; 
    #else
    plugin->typeCode = (struct RTICdrTypeCode *) 
    &rti::topic::dynamic_type<BenchmarkMessageTypePlainHelper>::get().native();
    #endif
    plugin->languageKind = PRES_TYPEPLUGIN_CPPSTL_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    BenchmarkMessageTypePlainHelperPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    BenchmarkMessageTypePlainHelperPlugin_return_buffer;
    plugin->getBufferWithParams = NULL;
    plugin->returnBufferWithParams = NULL;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    BenchmarkMessageTypePlainHelperPlugin_get_serialized_sample_size;

    plugin->getWriterLoanedSampleFnc = NULL; 
    plugin->returnWriterLoanedSampleFnc = NULL;
    plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
    plugin->validateWriterLoanedSampleFnc = NULL;
    plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

    static const char * TYPE_NAME = "BenchmarkMessageTypePlainHelper";
    plugin->endpointTypeName = TYPE_NAME;
    plugin->isMetpType = RTI_TRUE;
    return plugin;
}

void
BenchmarkMessageTypePlainHelperPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
#undef RTI_CDR_CURRENT_SUBMODULE 
