//////////////////////////////////////////////////////////////////////////////
//
// License Agreement:
//
// The following are Copyright � 2008, Daniel �nnerby
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the author nor the names of other contributors may
//      be used to endorse or promote products derived from this software
//      without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

//////////////////////////////////////////////////////////////////////////////

#include <core/tracklist/Base.h>
#include <core/Query/ListBase.h>
#include <core/Query/TrackMetadata.h>
#include <core/Library/Base.h>

#include <set>
#include <sigslot/sigslot.h>



//////////////////////////////////////////////////////////////////////////////
namespace musik{ namespace core{ namespace tracklist {
//////////////////////////////////////////////////////////////////////////////

class LibraryList : public Base, public sigslot::has_slots<> {
    public:
        LibraryList(musik::core::LibraryPtr library);

        virtual musik::core::TrackPtr operator [](long position);
        virtual musik::core::TrackPtr TrackWithMetadata(long position);
        virtual musik::core::TrackPtr CurrentTrack();
        virtual musik::core::TrackPtr NextTrack();
        virtual musik::core::TrackPtr PreviousTrack();

        virtual bool SetPosition(long position);
        virtual long CurrentPosition();
        virtual long Size();
        virtual void Clear();

        virtual bool operator =(musik::core::tracklist::Base &tracklist);
        virtual bool operator +=(musik::core::tracklist::Base &tracklist);
        virtual bool operator +=(musik::core::TrackPtr track);
    
		virtual musik::core::LibraryPtr Library();

    private:
        //////////////////////////////////////////
		///\brief
		///Internal representation of the tracklist.
		///
        ///This is used instead of a std::vector<TrackPtr> because of
        ///speed and memory issues.
		//////////////////////////////////////////
		std::vector<DBINT> tracklist;

//        std::map<long,

        musik::core::LibraryPtr library;

        long currentPosition;
};

//////////////////////////////////////////////////////////////////////////////
} } } // musik::core::tracklist
//////////////////////////////////////////////////////////////////////////////