// Copyright (c) 2011, Cornell University
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of HyperDex nor the names of its contributors may be
//       used to endorse or promote products derived from this software without
//       specific prior written permission.
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

#ifndef hyperdex_replication_keyholder_h_
#define hyperdex_replication_keyholder_h_

// e
#include <e/intrusive_ptr.h>

// Replication
#include <hyperdex/replication/pending.h>

namespace hyperdex
{
namespace replication
{

class keyholder
{
    public:
        keyholder();

    public:
        std::map<uint64_t, e::intrusive_ptr<replication::pending> > pending_updates;
        std::map<uint64_t, e::intrusive_ptr<replication::pending> > blocked_updates;
        std::map<uint64_t, e::intrusive_ptr<replication::pending> > deferred_updates;

    private:
        friend class e::intrusive_ptr<keyholder>;

    private:
        size_t m_ref;
};

inline
keyholder :: keyholder()
    : pending_updates()
    , blocked_updates()
    , deferred_updates()
    , m_ref(0)
{
}

} // namespace replication
} // namespace hyperdex

#endif // hyperdex_replication_keyholder_h_
