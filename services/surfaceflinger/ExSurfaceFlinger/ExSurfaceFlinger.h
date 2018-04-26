/* Copyright (c) 2015, 2018, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ANDROID_EX_SURFACE_FLINGER_H
#define ANDROID_EX_SURFACE_FLINGER_H

#include "SurfaceFlinger.h"
#include "Layer.h"

namespace android {

class ExSurfaceFlinger : public SurfaceFlinger
{
public:
    ExSurfaceFlinger();

protected:
    friend class ExBufferLayer;
    friend class Layer;
    virtual void handleDPTransactionIfNeeded(
                     const Vector<DisplayState>& displays);
    virtual void setDisplayAnimating(const sp<const DisplayDevice>& hw,
                                     const int32_t& dpy);
    virtual bool IsHWCDisabled() { return mDebugDisableHWC; }
    virtual ~ExSurfaceFlinger();

    bool mDebugLogs;
    bool isDebug() { return mDebugLogs; }
    bool mDisableExtAnimation;
    bool mAnimating = false;

    static bool sAllowHDRFallBack;
    static bool AllowHDRFallBack() { return sAllowHDRFallBack; }
    Mutex mExtAnimationLock;
    Condition mExtAnimationCond;
    static bool regionDump;
    virtual status_t doDump(int fd, const Vector<String16>& args, bool asProto);
    virtual void dumpDrawCycle(bool prePrepare);

    struct {
      Mutex lock;
      const char *name = "/data/misc/display/dumpsys.txt";
      bool running = false;
      bool noLimit = false;
      bool replaceAfterCommit = false;
      long int position = 0;
    } mFileDump;

};

}; //namespace android

#endif // ANDROID_EX_SURFACE_FLINGER_H