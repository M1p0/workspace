#pragma once

#include "xzero.h"
#include "benchmark.h"

static void MemPool_MultiThreaded(benchmark::State& state) {
    void *pMemBlock = NULL;

    if (state.thread_index == 0)
    { // Setup code here.
    }

    while (state.KeepRunning())
    { // Run the test as normal.
        xzero::KG_GetFromDefaultMemPool(&pMemBlock, 1024);
        xzero::KG_PutIntoDefaultMemPool(&pMemBlock);
    }

    if (state.thread_index == 0)
    { // Teardown code here.
    }
}

BENCHMARK(MemPool_MultiThreaded)->Threads(4);
