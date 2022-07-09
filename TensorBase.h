// Tensor.h defines the base tensor

#include <array>
#include <tuple>
#include "I_Tensor.h"

template<typename T>
class TensorBase : public I_Tensor<T>
{
    public:
        TensorBase() = default;
        const std::size_t& rank() const {return m_Rank;};
        T& at(std::size_t& index) {throw("This is a rank 0 tensor!");};
    
    private:
        static const std::size_t m_Rank = 0;
};

template<typename T, std::size_t A>
class TensorBase : public I_Tensor<T>
{
    public:
        TensorBase() = default;
        virtual ~TensorBase() = default;
        T& at(std::size_t index)
        {
            return m_Tensor.at(index);
        }
    const std::size_t& rank() const override
    {
        return m_Rank;
    }

    private:
        std::array<T, A> m_Tensor;
        static const std::size_t m_Rank = 1;
};

// template<typename T, std::size_t A>
// T& TensorBase<T, A>::at(std::size_t index)
// {
//     return tensor.at(index);
// }

// template<typename T, std::size_t A>
// const std::size_t& TensorBase<T, A>::rank() const
// {
//     return 1;
// }

template <typename T, std::size_t A, std::size_t... B>
class TensorBase : public I_Tensor<T>
{
    public:
        virtual ~TensorBase() = default;
        template<std::size_t indexFirst, std::size_t...indices> 
        T& at(std::size_t&& indexFirst, ... std::size_t&& indices)
        {   //This function ONLY makes sense when the number of supplied indices are equal to the number of dimensions, which we are deducing by the rank-1
            if constexpr(sizeof...(indices) == (sizeof...(B)))
            {
                return m_Tensor.at(indexFirst)::at(...indices);
            }
            else
            {
                static_assert("Number of arguments does not equal rank!");
            }
        }

        const std::size_t& rank() const override {return m_Rank;};
        
    private:
        std::array<TensorBase<T, B...>, A> m_Tensor;
        static const size_t m_Rank(sizeof...(B) + 1);
};