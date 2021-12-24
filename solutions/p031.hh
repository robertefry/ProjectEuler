
#include "Scratch.hh"

namespace p031
{
    using namespace std;

    uint32_t count_permutations(vector<uint32_t> const& deliminations, size_t index, uint32_t target)
    {
        uint32_t permutations = 0;

        while (index < deliminations.size() && deliminations[index] > target)
        {
            index += 1;
        }
        if (index >= deliminations.size())
        {
            return 0;
        }
        if (deliminations[index] == target)
        {
            permutations += 1;
            index += 1;
        }
        while (index < deliminations.size())
        {
            permutations += count_permutations(deliminations,index,target-deliminations[index]);
            index += 1;
        }
        return permutations;
    }

    uint32_t count_permutations(vector<uint32_t> deliminations, uint32_t target)
    {
        std::sort(deliminations.begin(),deliminations.end(),std::greater<uint32_t>{});
        return count_permutations(deliminations,0,target);
    }

    std::string run()
    {
        vector<uint32_t> deliminations { 1,2,5,10,20,50,100,200 };
        uint32_t permutations = count_permutations(deliminations,200);
        return to_string(permutations);
    }

}
