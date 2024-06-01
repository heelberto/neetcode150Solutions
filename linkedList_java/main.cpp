#include <iostream>
#include <memory>
// using namespace std;

template <typename T>
class SLNode
{
public:
    // T Element();
    void SetElement(T x);
    std::shared_ptr<SLNode<T>> Next();
    void SetNext(std::shared_ptr<SLNode<T>> next);

private:
    T element_;
    std::shared_ptr<SLNode> next_;

    SLNode() : element_(0), next_(nullptr) {}

    T Element()
    {
        return element_;
    }
};

template <typename T>
class SLList
{
private:
    std::shared_ptr<SLNode> tail_;
    size_t size_;

    SLList() : tail_(std::make_shared<SLNode>(T(), nullptr)), size_(0) { tail_->SetNext(tail_); }
};

int main()
{

    SLNode<int> node1;

    return 0;
}