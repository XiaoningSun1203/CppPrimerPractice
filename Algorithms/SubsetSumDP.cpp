 #include <iostream>
 #include <vector>

 bool dp_subSet(std::vector<int> vec, std::vector<std::vector<bool>> store,int k,int sum)
 {
     for (int i = 1; i < k; ++i) {
         for (int j = 1; j < sum+1; ++j) {
             if (vec[i] > j)
             {
                 store[i][j] = store[i-1][j];//递归出口case3
             }
             else
             {
                 //向二维表内填入bool值
                 store[i][j] = store[i-1][j-vec[i]] or store[i-1][j];
             }
         }
     }
     return store[k-1][sum];//返回最终状态
 }

 int main()
 {
     std::vector<int> vec{3, 34, 4, 12, 5, 2};
    
     int sum = 13;//可改
     int k = int(vec.size());
     // 建立二维表格存储bool值
     std::vector<std::vector<bool>> store(vec.size(),std::vector<bool>(sum+1)) ;
     //递归出口case1
     for (int i = 1; i < vec.size(); ++i) {
         store[i][0] = true;
     }
     //递归出口case2
     for (int i = 0; i < sum + 1; ++i) {
         store[0][i] = false;
     }
     store[0][vec[0]] = true;
     std::cout << std::boolalpha;
     std::cout << dp_subSet(vec, store, k, sum) << std::endl;
     return 0;
 }
