

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

int32_t BenchmarkMessageTypeConstOffset::seqNum() const
{
    static const rti::flat::offset_t offsets[] = {0, 0, 0, 0};
    return deserialize<int32_t >(offsets);
}

DDS_UnsignedLongLong BenchmarkMessageTypeConstOffset::sourceTimestampMicrosec() const
{
    static const rti::flat::offset_t offsets[] = {4, 4, 4, 4};
    return deserialize<DDS_UnsignedLongLong >(offsets);
}

const rti::flat::PrimitiveArrayOffset<uint8_t, (100000)> BenchmarkMessageTypeConstOffset::buffer() const
{
    static const rti::flat::offset_t offsets[] = {12, 12, 12, 12};
    return get_member<const rti::flat::PrimitiveArrayOffset<uint8_t, (100000)> >(offsets);}

int32_t BenchmarkMessageTypeOffset::seqNum() const
{
    static const rti::flat::offset_t offsets[] = {0, 0, 0, 0};
    return deserialize<int32_t >(offsets);
}

bool BenchmarkMessageTypeOffset::seqNum(int32_t value)
{
    static const rti::flat::offset_t offsets[] = {0, 0, 0, 0};
    return serialize(offsets, value);

}

DDS_UnsignedLongLong BenchmarkMessageTypeOffset::sourceTimestampMicrosec() const
{
    static const rti::flat::offset_t offsets[] = {4, 4, 4, 4};
    return deserialize<DDS_UnsignedLongLong >(offsets);
}

bool BenchmarkMessageTypeOffset::sourceTimestampMicrosec(DDS_UnsignedLongLong value)
{
    static const rti::flat::offset_t offsets[] = {4, 4, 4, 4};
    return serialize(offsets, value);

}

const rti::flat::PrimitiveArrayOffset<uint8_t, (100000)> BenchmarkMessageTypeOffset::buffer() const
{
    static const rti::flat::offset_t offsets[] = {12, 12, 12, 12};
    return get_member<const rti::flat::PrimitiveArrayOffset<uint8_t, (100000)> >(offsets);}

rti::flat::PrimitiveArrayOffset<uint8_t, (100000)> BenchmarkMessageTypeOffset::buffer()
{
    static const rti::flat::offset_t offsets[] = {12, 12, 12, 12};
    return get_member<rti::flat::PrimitiveArrayOffset<uint8_t, (100000)> >(offsets);}

// ---- BenchmarkMessageTypePlainHelper: 

BenchmarkMessageTypePlainHelper::BenchmarkMessageTypePlainHelper() :
    m_seqNum_ (0) ,
    m_sourceTimestampMicrosec_ (0ull)  {
        rti::core::fill_array<uint8_t>( m_buffer_, 0);
}   

BenchmarkMessageTypePlainHelper::BenchmarkMessageTypePlainHelper (
    int32_t seqNum,
    rti::core::uint64 sourceTimestampMicrosec,
    const dds::core::array<uint8_t, 100000>& buffer)
    :
        m_seqNum_( seqNum ),
        m_sourceTimestampMicrosec_( sourceTimestampMicrosec ),
        m_buffer_( buffer ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
BenchmarkMessageTypePlainHelper::BenchmarkMessageTypePlainHelper(BenchmarkMessageTypePlainHelper&& other_) OMG_NOEXCEPT  :m_seqNum_ (std::move(other_.m_seqNum_))
,
m_sourceTimestampMicrosec_ (std::move(other_.m_sourceTimestampMicrosec_))
,
m_buffer_ (std::move(other_.m_buffer_))
{
} 

BenchmarkMessageTypePlainHelper& BenchmarkMessageTypePlainHelper::operator=(BenchmarkMessageTypePlainHelper&&  other_) OMG_NOEXCEPT {
    BenchmarkMessageTypePlainHelper tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void BenchmarkMessageTypePlainHelper::swap(BenchmarkMessageTypePlainHelper& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_seqNum_, other_.m_seqNum_);
    swap(m_sourceTimestampMicrosec_, other_.m_sourceTimestampMicrosec_);
    swap(m_buffer_, other_.m_buffer_);
}  

bool BenchmarkMessageTypePlainHelper::operator == (const BenchmarkMessageTypePlainHelper& other_) const {
    if (m_seqNum_ != other_.m_seqNum_) {
        return false;
    }
    if (m_sourceTimestampMicrosec_ != other_.m_sourceTimestampMicrosec_) {
        return false;
    }
    if (m_buffer_ != other_.m_buffer_) {
        return false;
    }
    return true;
}
bool BenchmarkMessageTypePlainHelper::operator != (const BenchmarkMessageTypePlainHelper& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const BenchmarkMessageTypePlainHelper& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "seqNum: " << sample.seqNum()<<", ";
    o << "sourceTimestampMicrosec: " << sample.sourceTimestampMicrosec()<<", ";
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

                static DDS_TypeCode BenchmarkMessageType_g_tc_buffer_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,100000, NULL,NULL);

                static DDS_TypeCode_Member BenchmarkMessageType_g_tc_members[3]=
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
                        (char *)"sourceTimestampMicrosec",/* Member name */
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
                        (char *)"buffer",/* Member name */
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
                    }
                };

                static DDS_TypeCode BenchmarkMessageType_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_FINAL_EXTENSIBILITY| DDS_TK_FLAT_DATA_LANGUAGE_BINDING| DDS_TK_SHMEM_REF_TRANSFER_MODE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"BenchmarkMessageType", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
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

                BenchmarkMessageType_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                BenchmarkMessageType_g_tc_buffer_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_octet;
                BenchmarkMessageType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                BenchmarkMessageType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                BenchmarkMessageType_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& BenchmarkMessageType_g_tc_buffer_array;

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

                BenchmarkMessageType_g_tc._data._sampleAccessInfo = sample_access_info();
                BenchmarkMessageType_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &BenchmarkMessageType_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo BenchmarkMessageType_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo BenchmarkMessageType_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &BenchmarkMessageType_g_sampleAccessInfo;
                }

                BenchmarkMessageType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) 0;
                BenchmarkMessageType_g_memberAccessInfos[0].bindingMemberValueOffset[1] = 
                (RTIXCdrUnsignedLong) 0;
                BenchmarkMessageType_g_memberAccessInfos[0].bindingMemberValueOffset[2] = 
                (RTIXCdrUnsignedLong) 0;
                BenchmarkMessageType_g_memberAccessInfos[0].bindingMemberValueOffset[3] = 
                (RTIXCdrUnsignedLong) 0;

                BenchmarkMessageType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) 4;
                BenchmarkMessageType_g_memberAccessInfos[1].bindingMemberValueOffset[1] = 
                (RTIXCdrUnsignedLong) 4;
                BenchmarkMessageType_g_memberAccessInfos[1].bindingMemberValueOffset[2] = 
                (RTIXCdrUnsignedLong) 4;
                BenchmarkMessageType_g_memberAccessInfos[1].bindingMemberValueOffset[3] = 
                (RTIXCdrUnsignedLong) 4;

                BenchmarkMessageType_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) 12;
                BenchmarkMessageType_g_memberAccessInfos[2].bindingMemberValueOffset[1] = 
                (RTIXCdrUnsignedLong) 12;
                BenchmarkMessageType_g_memberAccessInfos[2].bindingMemberValueOffset[2] = 
                (RTIXCdrUnsignedLong) 12;
                BenchmarkMessageType_g_memberAccessInfos[2].bindingMemberValueOffset[3] = 
                (RTIXCdrUnsignedLong) 12;

                BenchmarkMessageType_g_sampleAccessInfo.memberAccessInfos = 
                BenchmarkMessageType_g_memberAccessInfos;

                BenchmarkMessageType_g_sampleAccessInfo.typeSize[0] = (RTIXCdrUnsignedLong) 
                BenchmarkMessageTypeOffset::serialized_size(0);
                BenchmarkMessageType_g_sampleAccessInfo.typeSize[1] = (RTIXCdrUnsignedLong) 
                BenchmarkMessageTypeOffset::serialized_size(1);
                BenchmarkMessageType_g_sampleAccessInfo.typeSize[2] = (RTIXCdrUnsignedLong) 
                BenchmarkMessageTypeOffset::serialized_size(2);
                BenchmarkMessageType_g_sampleAccessInfo.typeSize[3] = (RTIXCdrUnsignedLong) 
                BenchmarkMessageTypeOffset::serialized_size(3);   

                BenchmarkMessageType_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_FLAT_DATA_CPP_03_STL ;

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

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code<BenchmarkMessageTypePlainHelper> {
            static DDS_TypeCode * get()
            {
                using namespace rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode BenchmarkMessageTypePlainHelper_g_tc_buffer_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,100000, NULL,NULL);

                static DDS_TypeCode_Member BenchmarkMessageTypePlainHelper_g_tc_members[3]=
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
                        (char *)"sourceTimestampMicrosec",/* Member name */
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
                        (char *)"buffer",/* Member name */
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
                    }
                };

                static DDS_TypeCode BenchmarkMessageTypePlainHelper_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_FINAL_EXTENSIBILITY| DDS_TK_SHMEM_REF_TRANSFER_MODE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"BenchmarkMessageTypePlainHelper", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        BenchmarkMessageTypePlainHelper_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for BenchmarkMessageTypePlainHelper*/

                if (is_initialized) {
                    return &BenchmarkMessageTypePlainHelper_g_tc;
                }

                BenchmarkMessageTypePlainHelper_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                BenchmarkMessageTypePlainHelper_g_tc_buffer_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_octet;
                BenchmarkMessageTypePlainHelper_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                BenchmarkMessageTypePlainHelper_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                BenchmarkMessageTypePlainHelper_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& BenchmarkMessageTypePlainHelper_g_tc_buffer_array;

                /* Initialize the values for member annotations. */
                BenchmarkMessageTypePlainHelper_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                BenchmarkMessageTypePlainHelper_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                BenchmarkMessageTypePlainHelper_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                BenchmarkMessageTypePlainHelper_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                BenchmarkMessageTypePlainHelper_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                BenchmarkMessageTypePlainHelper_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                BenchmarkMessageTypePlainHelper_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageTypePlainHelper_g_tc_members[1]._annotations._defaultValue._u.ulong_long_value = 0ull;
                BenchmarkMessageTypePlainHelper_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageTypePlainHelper_g_tc_members[1]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                BenchmarkMessageTypePlainHelper_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                BenchmarkMessageTypePlainHelper_g_tc_members[1]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                BenchmarkMessageTypePlainHelper_g_tc._data._sampleAccessInfo = sample_access_info();
                BenchmarkMessageTypePlainHelper_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &BenchmarkMessageTypePlainHelper_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                BenchmarkMessageTypePlainHelper *sample;

                static RTIXCdrMemberAccessInfo BenchmarkMessageTypePlainHelper_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo BenchmarkMessageTypePlainHelper_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &BenchmarkMessageTypePlainHelper_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    BenchmarkMessageTypePlainHelper);
                if (sample == NULL) {
                    return NULL;
                }

                BenchmarkMessageTypePlainHelper_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->seqNum() - (char *)sample);

                BenchmarkMessageTypePlainHelper_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->sourceTimestampMicrosec() - (char *)sample);

                BenchmarkMessageTypePlainHelper_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->buffer() - (char *)sample);

                BenchmarkMessageTypePlainHelper_g_sampleAccessInfo.memberAccessInfos = 
                BenchmarkMessageTypePlainHelper_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(BenchmarkMessageTypePlainHelper);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        BenchmarkMessageTypePlainHelper_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        BenchmarkMessageTypePlainHelper_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                BenchmarkMessageTypePlainHelper_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                BenchmarkMessageTypePlainHelper_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer<BenchmarkMessageTypePlainHelper>;

                BenchmarkMessageTypePlainHelper_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &BenchmarkMessageTypePlainHelper_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin BenchmarkMessageTypePlainHelper_g_typePlugin = 
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

                return &BenchmarkMessageTypePlainHelper_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const dds::core::xtypes::StructType& dynamic_type<BenchmarkMessageTypePlainHelper>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<BenchmarkMessageTypePlainHelper>::get())));
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
        RTIBool topic_type_support<BenchmarkMessageType>::native_initialize_sample(void *sample)
        {
            try {
                topic_type_support<BenchmarkMessageType>::reset_sample(*(BenchmarkMessageType *)sample);
            } catch (...) {
                return RTI_FALSE; 
            }
            return RTI_TRUE;
        }

        void topic_type_support<BenchmarkMessageType>::reset_sample(BenchmarkMessageType& sample) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support<BenchmarkMessageType>::allocate_sample(BenchmarkMessageType& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            // Nothing to do
        }

        void topic_type_support<BenchmarkMessageTypePlainHelper>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                BenchmarkMessageTypePlainHelperPlugin_new,
                BenchmarkMessageTypePlainHelperPlugin_delete);
        }

        std::vector<char>& topic_type_support<BenchmarkMessageTypePlainHelper>::to_cdr_buffer(
            std::vector<char>& buffer, 
            const BenchmarkMessageTypePlainHelper& sample,
            dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = BenchmarkMessageTypePlainHelperPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = BenchmarkMessageTypePlainHelperPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<BenchmarkMessageTypePlainHelper>::from_cdr_buffer(BenchmarkMessageTypePlainHelper& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = BenchmarkMessageTypePlainHelperPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create BenchmarkMessageTypePlainHelper from cdr buffer");
        }
        RTIBool topic_type_support<BenchmarkMessageTypePlainHelper>::native_initialize_sample(void *sample)
        {
            try {
                topic_type_support<BenchmarkMessageTypePlainHelper>::reset_sample(*(BenchmarkMessageTypePlainHelper *)sample);
            } catch (...) {
                return RTI_FALSE; 
            }
            return RTI_TRUE;
        }

        void topic_type_support<BenchmarkMessageTypePlainHelper>::reset_sample(BenchmarkMessageTypePlainHelper& sample) 
        {
            sample.seqNum(0);
            sample.sourceTimestampMicrosec(0ull);
            rti::topic::reset_sample(sample.buffer());
        }

        void topic_type_support<BenchmarkMessageTypePlainHelper>::allocate_sample(BenchmarkMessageTypePlainHelper& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            rti::topic::allocate_sample(sample.buffer(),  -1, -1);
        }

    }
}  

namespace rti { 
    namespace xcdr {
        RTIXCdrInterpreterPrograms * type_programs<BenchmarkMessageType>::get() 
        {
            return rti::xcdr::ProgramsSingleton<
            BenchmarkMessageType,
            RTI_XCDR_INITIALIZE_SAMPLE_PROGRAM,
            true, true, true
            >::get_instance();
        }

    } 
}

