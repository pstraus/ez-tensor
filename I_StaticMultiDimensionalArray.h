// Abstract Tensor Interface
template<class T>
class I_StaticMultiDimensionalArray
{
    public:
        virtual ~I_StaticMultiDimensionalArray() = default;
        //virtual T& at(decltype(std::size_t)... indexFinal) = 0;
        virtual const std::size_t& rank() const = 0;

};
