// Tensor.h defines the base tensor

#include <array>
#include <tuple>
#include "I_StaticMultiDimensionalArray.h"

template<typename T, std::size_t... N> class StaticMultiDimensionalArray;

template<typename T, std::size_t A>
class StaticMultiDimensionalArray<T, A> : public I_StaticMultiDimensionalArray<T>
{
    public:
        StaticMultiDimensionalArray() = default;
        virtual ~StaticMultiDimensionalArray() = default;
        virtual T& at(std::size_t index)
        {
            return m_Tensor.at(index);
        }
    const std::size_t& rank() const override
    {
        return m_Rank;
    }

    private:
        std::array<T, A> m_Tensor;
        const std::size_t m_Rank = 1;
};

// template<typename T, std::size_t A>
// T& StaticMultiDimensionalArray<T, A>::at(std::size_t index)
// {
//     return tensor.at(index);
// }

// template<typename T, std::size_t A>
// const std::size_t& StaticMultiDimensionalArray<T, A>::rank() const
// {
//     return 1;
// }

template <typename T, std::size_t A, std::size_t... B>
class StaticMultiDimensionalArray<T, A, B...> : public I_StaticMultiDimensionalArray<T>
{
    public:
        virtual ~StaticMultiDimensionalArray() = default;
        //T& at(std::size_t & indexFirst, indices&...)
        T& at(std::size_t indexFirst, decltype(B)... indices)
        {   //This function ONLY makes sense when the number of supplied indices are equal to the number of dimensions, which we are deducing by the rank-1
            if constexpr(sizeof...(indices) == (sizeof...(B)))
            {
                return m_Tensor.at(indexFirst).at(indices...);
            }
            else
            {
                static_assert("Number of arguments does not equal rank!");
            }
        }

        const std::size_t& rank() const override {return m_Rank;};
        
    private:
        std::array<StaticMultiDimensionalArray<T, B...>, A> m_Tensor;
        const size_t m_Rank{sizeof...(B) + 1};
};