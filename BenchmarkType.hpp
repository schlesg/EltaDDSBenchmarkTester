

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from BenchmarkType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef BenchmarkType_223200961_hpp
#define BenchmarkType_223200961_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"
#include "rti/topic/flat/FlatData.hpp"

#include "rti/zcopy/rtizcopy.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport BenchmarkMessageTypeConstOffset 
: public rti::flat::FinalOffset<BenchmarkMessageTypeConstOffset> {
  public:
    enum { required_alignment = 4 };

    static rti::flat::offset_t serialized_size(rti::flat::offset_t initial_position)
    {
        static const rti::flat::offset_t sizes[] = {100012, 100012, 100012, 100012};
        return sizes[initial_position % 4];
    }

    // Null offset
    BenchmarkMessageTypeConstOffset()
    {
    }

    // Constructor is for internal use only
    BenchmarkMessageTypeConstOffset(
        const rti::flat::SampleBase *sample, 
        rti::flat::offset_t offset)
        : rti::flat::FinalOffset<BenchmarkMessageTypeConstOffset>(const_cast<rti::flat::SampleBase *>(sample), offset)
    {
    }

    int32_t seqNum() const; 
    DDS_UnsignedLongLong sourceTimestampMicrosec() const; 
    const rti::flat::PrimitiveArrayOffset<uint8_t, (100000)> buffer() const; 
};
class NDDSUSERDllExport BenchmarkMessageTypeOffset 
: public rti::flat::FinalOffset<BenchmarkMessageTypeOffset> {
  public:
    typedef BenchmarkMessageTypeConstOffset ConstOffset;

    enum { required_alignment = 4 };

    static rti::flat::offset_t serialized_size(rti::flat::offset_t initial_position)
    {
        static const rti::flat::offset_t sizes[] = {100012, 100012, 100012, 100012};
        return sizes[initial_position % 4];
    }

    // Null offset
    BenchmarkMessageTypeOffset()
    {
    }

    // Constructor is for internal use only
    BenchmarkMessageTypeOffset(
        rti::flat::SampleBase *sample, 
        rti::flat::offset_t offset)
        : rti::flat::FinalOffset<BenchmarkMessageTypeOffset>(sample, offset)
    {
    }

    // Const accessors
    int32_t seqNum() const; 
    DDS_UnsignedLongLong sourceTimestampMicrosec() const; 
    const rti::flat::PrimitiveArrayOffset<uint8_t, (100000)> buffer() const; 

    // Modifiers
    bool seqNum(int32_t value);
    bool sourceTimestampMicrosec(DDS_UnsignedLongLong value);
    rti::flat::PrimitiveArrayOffset<uint8_t, (100000)> buffer(); 
};

typedef rti::flat::Sample<BenchmarkMessageTypeOffset> BenchmarkMessageType;

class NDDSUSERDllExport BenchmarkMessageTypePlainHelper {
  public:
    BenchmarkMessageTypePlainHelper();

    BenchmarkMessageTypePlainHelper(
        int32_t seqNum,
        rti::core::uint64 sourceTimestampMicrosec,
        const dds::core::array<uint8_t, 100000>& buffer);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    BenchmarkMessageTypePlainHelper (BenchmarkMessageTypePlainHelper&&) = default;
    BenchmarkMessageTypePlainHelper& operator=(BenchmarkMessageTypePlainHelper&&) = default;
    BenchmarkMessageTypePlainHelper& operator=(const BenchmarkMessageTypePlainHelper&) = default;
    BenchmarkMessageTypePlainHelper(const BenchmarkMessageTypePlainHelper&) = default;
    #else
    BenchmarkMessageTypePlainHelper(BenchmarkMessageTypePlainHelper&& other_) OMG_NOEXCEPT;  
    BenchmarkMessageTypePlainHelper& operator=(BenchmarkMessageTypePlainHelper&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    int32_t& seqNum() OMG_NOEXCEPT {
        return m_seqNum_;
    }

    const int32_t& seqNum() const OMG_NOEXCEPT {
        return m_seqNum_;
    }

    void seqNum(int32_t value) {
        m_seqNum_ = value;
    }

    rti::core::uint64& sourceTimestampMicrosec() OMG_NOEXCEPT {
        return m_sourceTimestampMicrosec_;
    }

    const rti::core::uint64& sourceTimestampMicrosec() const OMG_NOEXCEPT {
        return m_sourceTimestampMicrosec_;
    }

    void sourceTimestampMicrosec(rti::core::uint64 value) {
        m_sourceTimestampMicrosec_ = value;
    }

    dds::core::array<uint8_t, 100000>& buffer() OMG_NOEXCEPT {
        return m_buffer_;
    }

    const dds::core::array<uint8_t, 100000>& buffer() const OMG_NOEXCEPT {
        return m_buffer_;
    }

    void buffer(const dds::core::array<uint8_t, 100000>& value) {
        m_buffer_ = value;
    }

    bool operator == (const BenchmarkMessageTypePlainHelper& other_) const;
    bool operator != (const BenchmarkMessageTypePlainHelper& other_) const;

    void swap(BenchmarkMessageTypePlainHelper& other_) OMG_NOEXCEPT ;

  private:

    int32_t m_seqNum_;
    rti::core::uint64 m_sourceTimestampMicrosec_;
    dds::core::array<uint8_t, 100000> m_buffer_;

};

inline void swap(BenchmarkMessageTypePlainHelper& a, BenchmarkMessageTypePlainHelper& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BenchmarkMessageTypePlainHelper& sample);

namespace rti {
    namespace zcopy {
        namespace topic {
            template<>
            struct is_zcopy_type<BenchmarkMessageType> : public dds::core::true_type {};
            template<>
            struct is_zcopy_and_flat_data_type<BenchmarkMessageType> : public dds::core::true_type {};
            template<>
            struct is_zcopy_type<BenchmarkMessageTypePlainHelper> : public dds::core::true_type {};
            template<>
            struct is_zcopy_type_only<BenchmarkMessageTypePlainHelper> : public dds::core::true_type {};
        }
    }
}

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name<BenchmarkMessageType> {
            NDDSUSERDllExport static std::string value() {
                return "BenchmarkMessageType";
            }
        };

        template<>
        struct is_topic_type<BenchmarkMessageType> : public dds::core::true_type {};

        template<>
        struct topic_type_support<BenchmarkMessageType> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BenchmarkMessageType& sample,
                dds::core::policy::DataRepresentationId representation 
                = dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BenchmarkMessageType& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport
            static RTIBool native_initialize_sample(void *sample);
            NDDSUSERDllExport 
            static void reset_sample(BenchmarkMessageType& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BenchmarkMessageType& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<BenchmarkMessageTypePlainHelper> {
            NDDSUSERDllExport static std::string value() {
                return "BenchmarkMessageTypePlainHelper";
            }
        };

        template<>
        struct is_topic_type<BenchmarkMessageTypePlainHelper> : public dds::core::true_type {};

        template<>
        struct topic_type_support<BenchmarkMessageTypePlainHelper> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BenchmarkMessageTypePlainHelper& sample,
                dds::core::policy::DataRepresentationId representation 
                = dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BenchmarkMessageTypePlainHelper& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport
            static RTIBool native_initialize_sample(void *sample);
            NDDSUSERDllExport 
            static void reset_sample(BenchmarkMessageTypePlainHelper& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BenchmarkMessageTypePlainHelper& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type<BenchmarkMessageType> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility<BenchmarkMessageType> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::FINAL;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type<BenchmarkMessageTypePlainHelper> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility<BenchmarkMessageTypePlainHelper> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::FINAL;                
        };

    }
}

namespace rti { namespace xcdr {
        template <>
        struct type_programs<BenchmarkMessageType> {
            static RTIXCdrInterpreterPrograms * get();
        };
    } }

namespace rti { namespace flat {

        template <>
        struct flat_type_traits<BenchmarkMessageType> {
            typedef BenchmarkMessageTypePlainHelper plain_type;
            typedef BenchmarkMessageTypeOffset offset;
        };

        template <>
        struct flat_type_traits<BenchmarkMessageTypeOffset> {
            typedef BenchmarkMessageType flat_type;
            typedef BenchmarkMessageTypePlainHelper plain_type;
        };

        template <>
        struct flat_type_traits<BenchmarkMessageTypeConstOffset> 
        : flat_type_traits<BenchmarkMessageTypeOffset> {
        };

    } } // namespace rti::flat

#include "rti/flat/FlatSampleImpl.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // BenchmarkType_223200961_hpp

