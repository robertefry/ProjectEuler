
#include "Scratch.hh"
#include "math/factorial.hh"

namespace p024
{
    using namespace std;

    list<uint32_t> get_permutation(list<uint32_t> dictionary, size_t index)
    {
        list<uint32_t> result;

        while (not dictionary.empty())
        {
            size_t const f = math::factorial( dictionary.size() - 1 );
            size_t const n = index / f; // integer division

            result.splice(result.end(),dictionary,std::next(dictionary.begin(),n));
            index -= n * f;
        }
        return result;
    }

    std::string run()
    {
        list<uint32_t> dictionary { 0,1,2,3,4,5,6,7,8,9 };
        list<uint32_t> permutation = get_permutation(dictionary,1'000'000-1);
        return util::make_stringlist(permutation).to_string("");
    }

}
