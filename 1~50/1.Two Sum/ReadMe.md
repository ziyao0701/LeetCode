# Two Sum 兩數之和

## 題目說明
給定一個整數陣列 nums 和一個目標值 target，從陣列中找出和為目標值 target 的兩個整數，並回傳這兩個數字在陣列中的索引值（index）。

### 範例
- Input: nums = [2,7,11,15], target = 9  
  Output: [0,1]  
  Explanation: nums[0] + nums[1] = 2 + 7 = 9

- Input: nums = [3,2,4], target = 6  
  Output: [1,2]

- Input nums = [3,3], target = 6  
  Output [0,1]

### 條件
- 2 <= nums.length <= 104
- -109 <= nums[i] <= 109
- -109 <= target <= 109
- Only one valid answer exists.

## 解題思路
1. 暴力法(Brute Force)

    使用兩層 for 迴圈，外層從 nums[0] 開始，內層則從下一個索引位置開始，逐一尋找和與 target 相符的數字，若遍歷後仍無符合者，則外層繼續測試下一個元素，直到找到符合條件的兩個索引為止。
    > Time Compelexity : O($n^2$)  
    > Space Complexity : O($1$)  
    > Disadvantage: 陣列長度過長時效能很差

2. **雜湊表(Hash Map)**
    
    使用 HashMap 記錄數值（key）及其對應索引（value），在遍歷陣列時，對每個元素計算其互補值 target - nums[i]，並檢查該互補值是否已存在於表中，若存在則可立即取得其索引並回傳。
    > Time Compelexity : O($n$)  
    > Space Complexity : O($1$)  
    > Disadvantage: 需要額外空間儲存 HashMap

### Key Concepts
- Array
- HashMap