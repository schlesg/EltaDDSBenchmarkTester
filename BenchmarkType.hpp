

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from BenchmarkType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef BenchmarkType_223201044_hpp
#define BenchmarkType_223201044_hpp

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

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
// On Windows, dll-export template instantiations of standard types used by
// other dll-exported types
template class NDDSUSERDllExport std::allocator<uint8_t>;
template class NDDSUSERDllExport std::vector<uint8_t >;
#endif
class NDDSUSERDllExport BenchmarkMessageType {
  public:
    BenchmarkMessageType();

    BenchmarkMessageType(
        int32_t seqNum,
        rti::core::uint64 sourceTimestampSec,
        rti::core::uint64 sourceTimestampMillisec,
        rti::core::uint64 sourceTimestampMicrosec,
        rti::core::uint64 sourceTimestampNanosec,
        const rti::core::bounded_sequence<uint8_t, 100000>& buffer);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    BenchmarkMessageType (BenchmarkMessageType&&) = default;
    BenchmarkMessageType& operator=(BenchmarkMessageType&&) = default;
    BenchmarkMessageType& operator=(const BenchmarkMessageType&) = default;
    BenchmarkMessageType(const BenchmarkMessageType&) = default;
    #else
    BenchmarkMessageType(BenchmarkMessageType&& other_) OMG_NOEXCEPT;  
    BenchmarkMessageType& operator=(BenchmarkMessageType&&  other_) OMG_NOEXCEPT;
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

    rti::core::uint64& sourceTimestampSec() OMG_NOEXCEPT {
        return m_sourceTimestampSec_;
    }

    const rti::core::uint64& sourceTimestampSec() const OMG_NOEXCEPT {
        return m_sourceTimestampSec_;
    }

    void sourceTimestampSec(rti::core::uint64 value) {
        m_sourceTimestampSec_ = value;
    }

    rti::core::uint64& sourceTimestampMillisec() OMG_NOEXCEPT {
        return m_sourceTimestampMillisec_;
    }

    const rti::core::uint64& sourceTimestampMillisec() const OMG_NOEXCEPT {
        return m_sourceTimestampMillisec_;
    }

    void sourceTimestampMillisec(rti::core::uint64 value) {
        m_sourceTimestampMillisec_ = value;
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

    rti::core::uint64& sourceTimestampNanosec() OMG_NOEXCEPT {
        return m_sourceTimestampNanosec_;
    }

    const rti::core::uint64& sourceTimestampNanosec() const OMG_NOEXCEPT {
        return m_sourceTimestampNanosec_;
    }

    void sourceTimestampNanosec(rti::core::uint64 value) {
        m_sourceTimestampNanosec_ = value;
    }

    rti::core::bounded_sequence<uint8_t, 100000>& buffer() OMG_NOEXCEPT {
        return m_buffer_;
    }

    const rti::core::bounded_sequence<uint8_t, 100000>& buffer() const OMG_NOEXCEPT {
        return m_buffer_;
    }

    void buffer(const rti::core::bounded_sequence<uint8_t, 100000>& value) {
        m_buffer_ = value;
    }

    bool operator == (const BenchmarkMessageType& other_) const;
    bool operator != (const BenchmarkMessageType& other_) const;

    void swap(BenchmarkMessageType& other_) OMG_NOEXCEPT ;

  private:

    int32_t m_seqNum_;
    rti::core::uint64 m_sourceTimestampSec_;
    rti::core::uint64 m_sourceTimestampMillisec_;
    rti::core::uint64 m_sourceTimestampMicrosec_;
    rti::core::uint64 m_sourceTimestampNanosec_;
    rti::core::bounded_sequence<uint8_t, 100000> m_buffer_;

};

inline void swap(BenchmarkMessageType& a, BenchmarkMessageType& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BenchmarkMessageType& sample);

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
            static void reset_sample(BenchmarkMessageType& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BenchmarkMessageType& sample, int, int);

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
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // BenchmarkType_223201044_hpp

