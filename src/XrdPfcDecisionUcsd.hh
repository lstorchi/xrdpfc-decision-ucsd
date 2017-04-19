#ifndef XRDPFCDECISIONUCSD_H
#define XRDPFCDECISIONUCSD_H

#include "XrdFileCache/XrdFileCacheDecision.hh"

#include <pcre.h>

class XrdSysError;

namespace XrdPfcDecisionUcsd
{
/**
 *  @class XrdPfcDecisionUcsd::Decision 
 *    XRootD Proxy File Cache Decision plugin in use at UCSD T2.
 *    Use as:
 *      pfc.decisionlib libXrdPfcDecisionUcsd.so params
 *    params should be separated by comma
 *  @Author: Matevz Tadel
 */

class Decision : public XrdFileCache::Decision
{
public:

   Decision(XrdSysError &log);

   virtual ~Decision();

   virtual bool ConfigDecision(const char* params);

   virtual bool Decide(const std::string &, XrdOss &) const;

   XrdSysError &m_log;
};    

}

extern "C"
{
   XrdFileCache::Decision *XrdFileCacheGetDecision(XrdSysError&);
}

#endif

