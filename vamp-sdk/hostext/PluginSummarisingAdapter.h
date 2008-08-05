/* -*- c-basic-offset: 4 indent-tabs-mode: nil -*-  vi:set ts=8 sts=4 sw=4: */

/*
    Vamp

    An API for audio analysis and feature extraction plugins.

    Centre for Digital Music, Queen Mary, University of London.
    Copyright 2006-2008 Chris Cannam and QMUL.
  
    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use, copy,
    modify, merge, publish, distribute, sublicense, and/or sell copies
    of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR
    ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
    CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

    Except as contained in this notice, the names of the Centre for
    Digital Music; Queen Mary, University of London; and Chris Cannam
    shall not be used in advertising or otherwise to promote the sale,
    use or other dealings in this Software without prior written
    authorization.
*/

#ifndef _VAMP_PLUGIN_SUMMARISING_ADAPTER_H_
#define _VAMP_PLUGIN_SUMMARISING_ADAPTER_H_

#include "PluginWrapper.h"

#include <set>

namespace Vamp {

namespace HostExt {

class PluginSummarisingAdapter : public PluginWrapper
{
public:
    PluginSummarisingAdapter(Plugin *plugin); // I take ownership of plugin
    virtual ~PluginSummarisingAdapter();

    FeatureSet process(const float *const *inputBuffers, RealTime timestamp);
    FeatureSet getRemainingFeatures();

    typedef std::set<RealTime> SegmentBoundaries;
    void setSummarySegmentBoundaries(const SegmentBoundaries &);

    enum SummaryType {
        Minimum,
        Maximum,
        Mean,
        Median,
        Mode,
        Sum,
        Variance,
        StandardDeviation,
        Count
    };

    FeatureSet getSummary(int output, SummaryType type);

protected:
    class Impl;
    Impl *m_impl;
};

}

}

#endif