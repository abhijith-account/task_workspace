#include <iostream>
#include <vector>
#include <algorithm> 

class ISortStrategy{
  public:
      virtual ~ISortStrategy()=default;
      virtual void sort(std::vector<int>& arr)=0;
};

class BubbleSortStrategy:public ISortStrategy{
  public:
      void sort(std::vector<int>& arr) override{
          int n=arr.size();
          for (int i=0;i<n-1;++i){
            for (int j=0;j<n-i-1;++j){
              if (arr[j]>arr[j+1]){
                  std::swap(arr[j],arr[j+1]);
              }
            }
          }
      }
};

class SelectionSortStrategy:public ISortStrategy{
  public:
      void sort(std::vector<int>& arr) override{
          int n=arr.size();
          for (int i=0;i<n-1;++i){
              int min_idx=i;
              for (int j=i+1;j<n;++j){
                  if (arr[j]<arr[min_idx]){
                      min_idx=j;
                  }
              }
              std::swap(arr[min_idx],arr[i]);
          }
      }
};

class Sorter{
  private:
      ISortStrategy* strategy=nullptr;
  public:
      void setStrategy(ISortStrategy* newStrategy){
        strategy=newStrategy;
      }
      std::vector<int> doSort(std::vector<int>& arr){
        std::vector<int> sortedResult=arr;
        if (strategy){
          strategy->sort(sortedResult);
        }
        return sortedResult;
      }
};

void printArray(const std::string& prefix,const std::vector<int>& arr){
    std::cout<<prefix<<":{";
    for (int num:arr){
      std::cout<<num<<"";
    }
    std::cout<<"}\n";
}

int main(){
    Sorter sorter;
    BubbleSortStrategy bubble;
    SelectionSortStrategy selection;
    
    std::vector<int> data1={5,3,8,1,9,2};
    sorter.setStrategy(&bubble);
    std::vector<int> one=sorter.doSort(data1);
    printArray("Result of BubbleSort strategy=",one);
    sorter.setStrategy(&selection);
    std::vector<int> two=sorter.doSort(data1);
    printArray("Result of Selection strategy",two);
}



    
          
            

