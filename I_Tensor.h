// Abstract Tensor Interface
template<class T>
class I_Tensor
{
    public:
        virtual ~I_Tensor() = default;
        //template<std::size_t indexFirst, std::size_t ...indexFinal>
        //virtual T& at(std::size_t& indexFirst, ...std::size_t& indexFinal) = 0;
        virtual const std::size_t& rank() const = 0;

};
