#include <iostream>
#include <vector>

using namespace std;

/*堆的实现||优先队列*/

class MyHeap{
private:
        vector<int> heap;
public:
        MyHeap() {}
        void push(int x){
                heap.push_back(x);
                swim();
        }
        int pop(){
                int x = heap[0];
                heap[0] = heap.back();
                heap.pop_back();
                sink();
                return x;
        }
        int top(){
                return heap[0];
        }
        void swim(){
                int n = heap.size(), pos = n;
                while(pos > 1 && heap[pos / 2 - 1] < heap[pos - 1]){
                        swap(heap[pos / 2 - 1], heap[pos - 1]);
                        pos = pos / 2;
                }
        }
        void sink(){
                int n = heap.size(), pos = 1;
                while(2 * pos <= n){
                        int i = 2 * pos;
                        if(heap[i] < heap[i+1]) i++;
                        if(heap[pos-1] < heap[i-1]){
                                swap(heap[pos-1], heap[i-1]);
                        }
                        pos = i;
                }
        }
};

int main(){
        MyHeap m;
        m.push(1);
        cout<<m.top()<<endl;
        m.push(2);
        cout<<m.top()<<endl;
        m.push(6);
        cout<<m.top()<<endl;
        m.push(3);
        cout<<m.top()<<endl;
        cout<<m.pop()<<endl;
        cout<<m.top()<<endl;
        
        return 0;
}
