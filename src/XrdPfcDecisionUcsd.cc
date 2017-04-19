/* 
   Implementation of a N2N class using the CMS TFC

   Rewritten, but adopted from upstream CMS sources
   Author: Brian Bockelman
   Original Author: Giulio.Eulisse@cern.ch
 */

#include <set>
#include <vector>
#include <string>

#include "XrdPfcDecisionUcsd.hh"
#include "XrdSys/XrdSysError.hh"

using namespace XrdPfcDecisionUcsd;

extern "C"
{
XrdFileCache::Decision *XrdFileCacheGetDecision(XrdSysError &log)
{
   return new Decision(log);
}
}

//==============================================================================

Decision::Decision(XrdSysError &log) : XrdFileCache::Decision(), m_log(log)
{
   m_log.Say("XrdPfcDecisionUcsd::Decision instantiated.");
}

Decision::~Decision()
{
   m_log.Say("XrdPfcDecisionUcsd::Decision terminated.");
}

bool Decision::ConfigDecision(const char* params)
{
   m_log.Say("Params: ", params);

   return true;
}

//==============================================================================

bool Decision::Decide(const std::string &, XrdOss &) const
{
   return true;
}
