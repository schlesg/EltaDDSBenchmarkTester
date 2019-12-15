

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from BenchmarkType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "BenchmarkType.hpp"
#include "BenchmarkTypePlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- BenchmarkMessageType: 

BenchmarkMessageType::BenchmarkMessageType() :
    m_seqNum_ (0) ,
    m_sourceTimestampSec_ (0ull) ,
    m_sourceTimestampMillisec_ (0ull) ,
    m_sourceTimestampMicrosec_ (0ull) ,
    m_sourceTimestampNanosec_ (0ull)  {
}   

BenchmarkMessageType::BenchmarkMessageType (
    int32_t seqNum,
    rti::core::uint64 sourceTimestampSec,
    rti::core::uint64 sourceTimestampMillisec,
    rti::core::uint64 sourceTimestampMicrosec,
    rti::core::uint64 sourceTimestampNanosec,
    const rti::core::bounded_sequence<uint8_t, 100000>& buffer)
    :
        m_seqNum_( seqNum ),
        m_sourceTimestampSec_( sourceTimestampSec ),
        m_sourceTimestampMillisec_( sourceTimestampMillisec ),
        m_sourceTimestampMicrosec_( sourceTimestampMicrosec ),
        m_sourceTimestampNanosec_( sourceTimestampNanosec ),
        m_buffer_( buffer ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
BenchmarkMessageType::BenchmarkMessageType(BenchmarkMessageType&& other_) OMG_NOEXCEPT  :m_seqNum_ (std::move(other_.m_seqNum_))
,
m_sourceTimestampSec_ (std::move(other_.m_sourceTimestampSec_))
,
m_sourceTimestampMillisec_ (std::move(other_.m_sourceTimestampMillisec_))
,
m_sourceTimestampMicrosec_ (std::move(other_.m_sourceTimestampMicrosec_))
,
m_sourceTimestampNanosec_ (std::move(other_.m_sourceTimestampNanosec_))
,
m_buffer_ (std::move(other_.m_buffer_))
{
} 

BenchmarkMessageType& BenchmarkMessageType::operator=(BenchmarkMessageType&&  other_) OMG_NOEXCEPT {
    BenchmarkMessageType tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void BenchmarkMessageType::swap(BenchmarkMessageType& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_seqNum_, other_.m_seqNum_);
    swap(m_sourceTimestampSec_, other_.m_sourceTimestampSec_);
    swap(m_sourceTimestampMillisec_, other_.m_sourceTimestampMillisec_);
    swap(m_sourceTimestampMicrosec_, other_.m_sourceTimestampMicrosec_);
    swap(m_sourceTimestampNanosec_, other_.m_sourceTimestampNanosec_);
    swap(m_buffer_, other_.m_buffer_);
}  

bool BenchmarkMessageType::operator == (const BenchmarkMessageType& other_) const {
    if (m_seqNum_ != other_.m_seqNum_) {
        return false;
    }
    if (m_sourceTimestampSec_ != other_.m_sourceTimestampSec_) {
        return false;
    }
    if (m_sourceTimestampMillisec_ != other_.m_sourceTimestampMillisec_) {
        return false;
    }
    if (m_sourceTimestampMicrosec_ != other_.m_sourceTimestampMicrosec_) {
        return false;
    }
    if (m_sourceTimestampNanosec_ != other_.m_sourceTimestampNanosec_) {
        return false;
    }
    if (m_buffer_ != other_.m_buffer_) {
        return false;
    }
    return true;
}
bool BenchmarkMessageType::operator != (const BenchmarkMessageType& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const BenchmarkMessageType& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "seqNum: " << sample.seqNum()<<", ";
    o << "sourceTimestampSec: " << sample.sourceTimestampSec()<<", ";
    o << "sourceTimestampMillisec: " << sample.sourceTimestampMillisec()<<", ";
    o << "sourceTimestampMicrosec: " << sample.sourceTimestampMicrosec()<<", ";
    o << "sourceTimestampNanosec: " << sample.sourceTimestampNanosec()<<", ";
    o << "buffer: " << sample.buffer() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code<BenchmarkMessageType> {
            static DDS_TypeCode * get()
            {
                using namespace rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode BenchmarkMessageType_g_tc_buffer_sequence;

                static DDS_TypeCode_Member BenchmarkMessageType_g_tc_members[6]=
                {

                    {
                        (char *)"seqNum",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"sourceTimestampSec",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"sourceTimestampMillisec",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"sourceTimestampMicrosec",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"sourceTimestampNanosec",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"buffer",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode BenchmarkMessageType_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"BenchmarkMessageType", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        6, /* Number of members */
                        BenchmarkMessageType_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for BenchmarkMessageType*/

                if (is_initialized) {
                    return &BenchmarkMessageType_g_tc;
                }

                BenchmarkMessageType_g_tc_buffer_sequence = initialize_sequence_typecode<rti::core::bounded_sequence<uint8_t, 100000> >((100000));

                BenchmarkMessageType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                BenchmarkMessageType_g_tc_buffer_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                BenchmarkMessageType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                BenchmarkMessageType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                BenchmarkMessageType_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                BenchmarkMessageType_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                BenchmarkMessageType_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                BenchmarkMessageType_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)& BenchmarkMessageType_g_tc_buffer_sequence;

                /* Initialize the values for member annotations. */
                BenchmarkMessageType_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                BenchmarkMessageType_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                BenchmarkMessageType_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                BenchmarkMessageType_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                BenchmarkMessageType_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                BenchmarkMessageType_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                BenchmarkMessageType_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[1]._annotations._defaultValue._u.ulong_long_value = 0ull;
                BenchmarkMessageType_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[1]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                BenchmarkMessageType_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[1]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                BenchmarkMessageType_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[2]._annotations._defaultValue._u.ulong_long_value = 0ull;
                BenchmarkMessageType_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[2]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                BenchmarkMessageType_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[2]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                BenchmarkMessageType_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[3]._annotations._defaultValue._u.ulong_long_value = 0ull;
                BenchmarkMessageType_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[3]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                BenchmarkMessageType_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[3]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                BenchmarkMessageType_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[4]._annotations._defaultValue._u.ulong_long_value = 0ull;
                BenchmarkMessageType_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[4]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                BenchmarkMessageType_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageType_g_tc_members[4]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                BenchmarkMessageType_g_tc._data._sampleAccessInfo = sample_access_info();
                BenchmarkMessageType_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &BenchmarkMessageType_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                BenchmarkMessageType *sample;

                static RTIXCdrMemberAccessInfo BenchmarkMessageType_g_memberAccessInfos[6] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo BenchmarkMessageType_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &BenchmarkMessageType_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    BenchmarkMessageType);
                if (sample == NULL) {
                    return NULL;
                }

                BenchmarkMessageType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->seqNum() - (char *)sample);

                BenchmarkMessageType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->sourceTimestampSec() - (char *)sample);

                BenchmarkMessageType_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->sourceTimestampMillisec() - (char *)sample);

                BenchmarkMessageType_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->sourceTimestampMicrosec() - (char *)sample);

                BenchmarkMessageType_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->sourceTimestampNanosec() - (char *)sample);

                BenchmarkMessageType_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->buffer() - (char *)sample);

                BenchmarkMessageType_g_sampleAccessInfo.memberAccessInfos = 
                BenchmarkMessageType_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(BenchmarkMessageType);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        BenchmarkMessageType_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        BenchmarkMessageType_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                BenchmarkMessageType_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                BenchmarkMessageType_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer<BenchmarkMessageType>;

                BenchmarkMessageType_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_03_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &BenchmarkMessageType_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin BenchmarkMessageType_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &BenchmarkMessageType_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const dds::core::xtypes::StructType& dynamic_type<BenchmarkMessageType>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<BenchmarkMessageType>::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support<BenchmarkMessageType>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                BenchmarkMessageTypePlugin_new,
                BenchmarkMessageTypePlugin_delete);
        }

        std::vector<char>& topic_type_support<BenchmarkMessageType>::to_cdr_buffer(
            std::vector<char>& buffer, 
            const BenchmarkMessageType& sample,
            dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = BenchmarkMessageTypePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = BenchmarkMessageTypePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<BenchmarkMessageType>::from_cdr_buffer(BenchmarkMessageType& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = BenchmarkMessageTypePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create BenchmarkMessageType from cdr buffer");
        }

        void topic_type_support<BenchmarkMessageType>::reset_sample(BenchmarkMessageType& sample) 
        {
            sample.seqNum(0);
            sample.sourceTimestampSec(0ull);
            sample.sourceTimestampMillisec(0ull);
            sample.sourceTimestampMicrosec(0ull);
            sample.sourceTimestampNanosec(0ull);
            rti::topic::reset_sample(sample.buffer());
        }

        void topic_type_support<BenchmarkMessageType>::allocate_sample(BenchmarkMessageType& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            rti::topic::allocate_sample(sample.buffer(),  100000, -1);
        }

    }
}  

