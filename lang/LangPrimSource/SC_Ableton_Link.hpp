#pragma once

#ifdef SC_ABLETON_LINK

#include "PyrKernel.h"
#include "PyrSched.h"
#include "GC.h"
#include "PyrPrimitive.h"
#include "PyrSymbol.h"

#include "SCBase.h"
#include "SC_Clock.hpp"

#include <ableton/Link.hpp>

class LinkClock : public TempoClock
{
public:
	LinkClock(VMGlobals *inVMGlobals, PyrObject* inTempoClockObj,
				double inTempo, double inBaseBeats, double inBaseSeconds);

	~LinkClock() {}

	void SetTempoAtBeat(double inTempo, double inBeats);
	void SetTempoAtTime(double inTempo, double inSeconds);
	void SetAll(double inTempo, double inBeats, double inSeconds);
	double BeatsToSecs(double beats) const;
	double SecsToBeats(double secs) const;

	void SetQuantum(double quantum);
        double GetLatency();
        void SetLatency(double latency);
	std::size_t NumPeers() const { return mLink.numPeers(); }

  static void Init();
  static std::chrono::microseconds GetInitTime() { return LinkClock::mInitTime; }

private:
	ableton::Link mLink;
	double mQuantum;
	double mLatency;
  static std::chrono::microseconds mInitTime;
};

#endif // SC_ABLETON_LINK
