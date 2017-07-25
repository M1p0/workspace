#include "xzero.h"
#include "mempool_benchmark.h"

//BENCHMARK_MAIN();
int main(int argc, char** argv)
{
    xzero::KG_GlobalMemLeakDetect globalMemLeakDetect;

    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv))
    {
        return 1;
    }
    ::benchmark::RunSpecifiedBenchmarks();
    ::system("PAUSE");
}
