// Copyright (c) 2014 Baidu, Inc.G
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Authors: Lei He (helei@qiyi.com)

#ifndef BRPC_CONCURRENCY_LIMITER_H
#define BRPC_CONCURRENCY_LIMITER_H
                                            
#include "brpc/describable.h"
#include "brpc/destroyable.h"
#include "brpc/extension.h"                       // Extension<T>

namespace brpc {

class ConcurrencyLimiter : public NonConstDescribable, public Destroyable {
public:
    ConcurrencyLimiter() {}

    virtual bool OnRequested() = 0;

    virtual void OnResponded(int error_code, int64_t latency) = 0;

    virtual ConcurrencyLimiter* New() const = 0;

    virtual int Expose(const butil::StringPiece& prefix) = 0;

    virtual ~ConcurrencyLimiter() {}

    virtual int MaxConcurrency() const = 0;

    virtual int& MaxConcurrency() = 0;

    virtual int CurrentMaxConcurrency() const = 0;
};

inline Extension<const ConcurrencyLimiter>* ConcurrencyLimiterExtension() {
    return Extension<const ConcurrencyLimiter>::instance();
}

}  // namespace brpc


#endif // BRPC_CONCURRENCY_LIMITER_H
