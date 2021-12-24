
#include <type_traits>

namespace math
{

    template <typename Tp>
        requires std::is_arithmetic_v<Tp>
    Tp factorial(Tp const& limit)
    {
        Tp result = 1;

        for (Tp n = 2; n <= limit; ++n)
        {
            result *= n;
        }
        return result;
    }

}
