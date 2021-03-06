// This file is generated by omniidl (C++ backend) - omniORB_4_1. Do not edit.

#include "Writer.hh"

OMNI_USING_NAMESPACE(omni)

static const char* _0RL_dyn_library_version = omniORB_4_1_dyn;

static ::CORBA::TypeCode::_Tracker _0RL_tcTrack(__FILE__);

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace Writer { 
  const ::CORBA::TypeCode_ptr _tc_mWriter = CORBA::TypeCode::PR_interface_tc("IDL:Writer/mWriter:1.0", "mWriter", &_0RL_tcTrack);
} 
#else
const ::CORBA::TypeCode_ptr Writer::_tc_mWriter = CORBA::TypeCode::PR_interface_tc("IDL:Writer/mWriter:1.0", "mWriter", &_0RL_tcTrack);
#endif

static void _0RL_Writer_mmWriter_marshal_fn(cdrStream& _s, void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  omniObjRef::_marshal(_o, _s);
}
static void _0RL_Writer_mmWriter_unmarshal_fn(cdrStream& _s, void*& _v)
{
  omniObjRef* _o = omniObjRef::_unMarshal(Writer::mWriter::_PD_repoId, _s);
  _v = _o;
}
static void _0RL_Writer_mmWriter_destructor_fn(void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  if (_o)
    omni::releaseObjRef(_o);
}

void operator<<=(::CORBA::Any& _a, Writer::mWriter_ptr _o)
{
  Writer::mWriter_ptr _no = Writer::mWriter::_duplicate(_o);
  _a.PR_insert(Writer::_tc_mWriter,
               _0RL_Writer_mmWriter_marshal_fn,
               _0RL_Writer_mmWriter_destructor_fn,
               _no->_PR_getobj());
}
void operator<<=(::CORBA::Any& _a, Writer::mWriter_ptr* _op)
{
  _a.PR_insert(Writer::_tc_mWriter,
               _0RL_Writer_mmWriter_marshal_fn,
               _0RL_Writer_mmWriter_destructor_fn,
               (*_op)->_PR_getobj());
  *_op = Writer::mWriter::_nil();
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, Writer::mWriter_ptr& _o)
{
  void* _v;
  if (_a.PR_extract(Writer::_tc_mWriter,
                    _0RL_Writer_mmWriter_unmarshal_fn,
                    _0RL_Writer_mmWriter_marshal_fn,
                    _0RL_Writer_mmWriter_destructor_fn,
                    _v)) {
    omniObjRef* _r = (omniObjRef*)_v;
    if (_r)
      _o = (Writer::mWriter_ptr)_r->_ptrToObjRef(Writer::mWriter::_PD_repoId);
    else
      _o = Writer::mWriter::_nil();
    return 1;
  }
  return 0;
}

