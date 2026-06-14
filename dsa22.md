# DSA Notes — Array Problems

---

## 1. Left Rotate Array by One Place

Phle 0th element ko ek **temp** me store krdo.

**Left rotation:** first one went to last
```
1, 2, 3, 4, 5  →  2, 3, 4, 5, 1
```

**Steps:**
```
temp = a[0]
```
Har ith index ko i-1 pe rkhna h — mtlb sbko ek ek piche karna h.

```
for (i = 1; i < n; i++) {
    arr[i-1] = arr[i];
}
arr[n-1] = temp;
```

- **TC:** O(n)
- **SC:** O(1) extra space  
  *(Given space is O(n), extra space is O(1))*

---

## 2. Left Rotate Array by D Places

### Observation
```
arr = [1, 2, 3, 4, 5, 6, 7]
D = 2
arr → [3, 4, 5, 6, 7, 1, 2]
```

- D = 7 → same array wapas aajayega
- D = 8 → same as D = 1  
- D = 15 → same as D = 1 (7+7+1)
- **Formula:** `D = D % N` ← smart way to reduce

---

### Approach 1 — Temp Array

D = 3 ho toh:
- Pehle 3 elements ek `temp[]` me store kro
- Remaining elements ko D places back shift kro
- Temp wale elements last me wapas rakho

```cpp
d = d % N;
int temp[d];
for (int i = 0; i < d; i++) {
    temp[i] = arr[i];
}
// shifting
for (int i = d; i < n; i++) {
    arr[i - d] = arr[i];
}
// put back temp at the end
for (int i = n - d; i < n; i++) {
    arr[i] = temp[i - (n - d)];
}
```

- **TC:** O(d) + O(n-d) + O(d) = O(n)
- **SC:** O(d) extra

---

### Approach 2 — Reverse Method (Optimal Space)

```
arr = [1, 2, 3, 4, 5, 6, 7]  →  [4, 5, 6, 7, 1, 2, 3]  (d = 3)
```

1. Reverse first part `[0, d)` → `3 2 1`
2. Reverse second part `[d, n)` → `7 6 5 4`
3. Array becomes: `3 2 1 7 6 5 4`
4. Reverse whole array → `4 5 6 7 1 2 3` ✅

```
reverse(a, a + d);
reverse(a + d, a + n);
reverse(a, a + n);
```

- **TC:** O(d) + O(n-d) + O(d) = O(2n)  ← TC thoda bda hua but
- **SC:** O(1) ← kuch extra nahi use kar rahe

> STL me `reverse` function already pre-written hota hai. C mein baar baar likhna padta hai.

---

## 3. Moving Zeroes to End

```
arr[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1}
```

Non-zero ko front me kro, last me zeros daaldo.

---

### Brute Force

Pickup all non-zero numbers and store in temp, phir original array ke front me place kro, end me zeros fill karo.

```cpp
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        vector<int> temp(arr.size());
        int k = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                temp[k] = arr[i];
                k++;
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            arr[i] = temp[i];
        }
        // filling zeros in the back
        for (int i = temp.size(); i < arr.size(); i++) {
            arr[i] = 0;
        }
    }
};
```

> ⚠️ `vector<int> temp(arr.size());` — size pehle se dena mandatory hai.  
> `vector<int> temp;` se index access karna invalid hai (size 0 hota hai initially).

- **TC:** O(2N)
- **SC:** O(x) to O(N)

---

### Optimal — Two Pointer

0 ko htana h toh aage ki shift hogi. Two pointer approach use karte hain.

**Steps:**
1. First 0 dhundho
2. Us index ke aage jo bhi non-zero mile, swap karo

```
j = -1;
for (i = 0; i < n; i++) {
    if (arr[i] == 0) {
        j = i;
        break;
    }
}
// O(N)

for (i = j + 1; i < n; i++) {
    if (arr[i] != 0) {
        swap(arr[i], arr[j]);
        j++;
    }
}
// O(n - x) remaining
```

- **TC:** O(n)
- **SC:** O(1)

---

## 4. Linear Search

Search kro ek number ko.

```
6, 7, 8, 4, 1
nums = 4
→ return 3 (0-based indexing)
```

```cpp
for (i = 0; i < n; i++) {
    if (arr[i] == nums)
        return i;
}
```

- First occurrence dega.
- Last occurrence ke liye: ulta chlao ya `return` baad mein likho (loop ke baad).
- Saari occurrences ke liye: ek array mein store karo.

> Easy peasy 😄

---

## 5. Find Union of Two Sorted Arrays (May Have Duplicates)

```
arr1: 1, 1, 2, 3, 4, 5
arr2: 2, 3, 4, 4, 5, 6
union: 1, 2, 3, 4, 5, 6
```

---

### Brute Force — Using Set

```cpp
set<int> st;
for (i = 0; i < n; i++) st.insert(arr[i]);
for (i = 0; i < n2; i++) st.insert(arr[i]);

// fill union from set
for (auto it : st) {
    union.push_back(it);
}
```

- **TC:** O(n1 log n + n2 log n) + O(n1 + n2)
- **SC:** O(n1 + n2) for set + O(n1 + n2) for union array

---

### Optimal — Two Pointer

Dono arrays pe ek ek pointer. Sorted hain to compare karte chalo, push karte chalo.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> Union;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++;
            }
            else if (arr2[j] < arr1[i]) {
                if (Union.empty() || Union.back() != arr2[j])
                    Union.push_back(arr2[j]);
                j++;
            }
            else {
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++; j++;
            }
        }

        while (i < n) {
            if (Union.empty() || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
        while (j < m) {
            if (Union.empty() || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }

        return Union;
    }
};
```

- **TC:** O(n1 + n2) — ek hi loop chla
- **SC:** O(n1 + n2) for output (koi alag temp array nahi)

---

## 6. Intersection of Two Sorted Arrays

```
a: 1, 2, 2, 3, 3, 4, 5, 6
b: 2, 3, 3, 5, 6, 6, 7

a ∩ b: 2, 3, 3, 5, 6
```

---

### Brute Force — Visited Array

```
vis[] = [0, 0, 0, 0, 0, 0, 0]  ← b ke size ka (initially all 0)
```

`b` mein jo mil gaya use visited mark kro, taki dobara count na ho.

```
for (i = 0 → n1) {
    for (j = 0 → n2) {
        if (a[i] == b[j] && vis[j] == 0) {
            arr.add(a[i]);
            vis[j] = 1;
            break;
        }
        if (b[j] > a[i]) break;  // sorted h, aage kuch nahi milega
    }
}
```

- **TC:** O(n1 * n2) worst case
- **SC:** O(n2) for visited array

---

### Optimal — Two Pointer

```
a: 1, 2, 2, 3, 3, 4, 5, 6
b: 2, 3, 3, 5, 6, 6, 7
```

- Agar `a[i] < b[j]` → `i++` (no match possible aage bhi)
- Agar `a[i] > b[j]` → `j++`
- Agar equal → push, `i++`, `j++`

> Ek ka bhi exceed hojaye toh stop. Done.

---

## 7. Missing Number

```
arr[] = [1, 2, 4, 5]
n = 5
→ missing: 3
```

---

### Brute Force — Linear Search

Check karo 1 hai? 2 hai? 3 hai?...

```cpp
for (i = 1; i <= n; i++) {
    flag = 0;
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] == i) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) return i;
}
```

- **TC:** O(n²)

---

### Better — Hashing

1 to n ke beech numbers hain, toh hash array bana lo.

```cpp
hash[n + 1] = {0};
for (i = 0; i < n; i++) {
    hash[arr[i]] = 1;
}
for (i = 1; i <= n; i++) {
    if (hash[i] == 0) return i;
}
```

- **TC:** O(N) + O(N) = O(2N)
- **SC:** O(N) for hash array

---

### Optimal 1 — Sum Formula

```
Sum of first n natural numbers = n(n+1)/2
```

```
missing = (n*(n+1)/2) - (sum of given array elements)
```

```cpp
return sum - s2;
```

- **TC:** O(N)
- **SC:** O(1)

---

### Optimal 2 — XOR

```
a ^ a = 0
a ^ 0 = a
```

XOR all numbers 1 to n → `xor1`  
XOR all array elements → `xor2`  
`xor1 ^ xor2` = missing number (baaki sab cancel ho jaayenge)

```cpp
xor1 = 0;
xor2 = 0;
for (i = 0; i < n - 1; i++) {
    xor2 = xor2 ^ arr[i];
    xor1 = xor1 ^ (i + 1);
}
xor1 = xor1 ^ N;  // last wala
return xor1 ^ xor2;
```

> **Ek hi loop** mein dono kaam kar sakte hain. XOR approach slightly better hai kyunki:
> - `n` ka cap 10^5 ho → n*n integer mein store nahi hoga
> - XOR kabhi bade numbers generate nahi karta

- **TC:** O(2N)
- **SC:** O(1)

---

## 8. Maximum Consecutive Ones

```
arr: 1, 1, 0, 1, 1, 1, 0, 1, 1
→ max consecutive ones: 3
```

Counter rakho. Jab 1 aaye → `cnt++`. Jab 0 aaye → `cnt = 0`. Har baar max update karo.

```cpp
int maxi = 0;
int cnt = 0;
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 1) {
        cnt++;
        maxi = max(maxi, cnt);
    }
    else {
        cnt = 0;
    }
}
return maxi;
```

- **TC:** O(N)

---

## 9. Find the Number That Appears Once (Others Appear Twice)

```
arr = [1, 1, 2, 3, 3, 4, 4]
→ answer: 2
```

---

### Brute Force — Linear Search

Pickup every number, linear search karo, count karo.

```
for i = 0 → n:
    num = arr[i]
    cnt = 0
    for j = 0 → n:
        if arr[j] == num: cnt++
    if cnt == 1: return num
```

- **TC:** O(n²)

---

### Better — Hashing

```cpp
// find max element first
for (i = 0; i < n; i++)
    maxi = max(maxi, arr[i]);

// create hash
hash[maxi + 1] = {0};
for (i = 0; i < n; i++)
    hash[arr[i]]++;

// find count == 1
for (i = 0; i < n; i++)
    if (hash[arr[i]] == 1) return arr[i];
```

- **TC:** O(3N)
- **SC:** O(max element) — agar sparse data ya negative numbers hain → `map` use karo

**Map approach:**

| Feature | `map` | `unordered_map` |
|---|---|---|
| Order | Keys sorted order mein | No order (random) |
| Internal Structure | Balanced BST (Red-Black Tree) | Hash Table |
| Time Complexity | O(log n) | Average O(1), worst O(n) |
| Faster? | Slower | Generally faster |
| Header | `<map>` | `<unordered_map>` |
| Use When | Sorted data chahiye | Fast lookup chahiye |

```cpp
for (auto it : mpp) {
    if (it.second == 1)
        return it.first;
}
```

- **TC:** O(n log m) + O(n/2 + 1) using ordered map
- **SC:** O(n) for map

---

### Optimal — XOR

```
a ^ a = 0
```

Saare elements XOR karo → sab cancel ho jaayenge, sirf jo ek baar aaya woh bachega.

```cpp
int xorr = 0;
for (int i = 0; i < n; i++)
    xorr ^= arr[i];
return xorr;
```

- **TC:** O(N)
- **SC:** O(1)

---

## 10. Longest Subarray with Sum K (K always positive)

```
arr[] = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3]
```

Contiguous part of the array jinka sum K ho, usmein longest dhundhna hai.

---

### Brute Force — O(n³)

```cpp
for i = 0 → n:
    for j = i → n:
        sum = 0
        for k = i → j:
            sum += a[k]
        if (sum == k) len = max(len, j - i + 1)
```

---

### Better — O(n²)

Third loop hatao, sum ko build karte jao:

```cpp
for i = 0 → n:
    sum = 0
    for j = i → n:
        sum += a[j]
        if (sum == k) len = max(len, j - i + 1)
```

---

### Better — Hashing + Prefix Sum

Reverse engineering: prefix sum `x` nikal lo. Agar `x - k` pehle mil chuka hai toh beech ka sum `k` hai.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> mp;
    int k = 5;
    vector<int> nums = {2, 3, 5, 3, 1, 1};
    auto summ = 0;
    int maxx = 0;

    for (int i = 0; i < nums.size(); i++) {
        summ = summ + nums[i];

        if (summ == k) {
            maxx = max(maxx, i + 1);
        }
        if (mp.find(summ - k) != mp.end()) {
            int len = i - mp[summ - k];
            maxx = max(maxx, len);
        }
        if (mp.find(summ) == mp.end()) {
            // agar ye prefix pehli baar aa raha hai tabhi store karo
            // kyunki isse hi bda wala milega iske baad jo bhi milega chota hoga
            mp[summ] = i;
        }
    }
    cout << "output: " << maxx << endl;
}
```

> Pehli baar aane pe hi store karo — kyunki agar pehle se stored hai toh woh longer subarray dega.

- **TC:** O(n log n) if ordered map, O(n) avg if unordered map
- **SC:** O(n) for map

> ⚠️ Prefix sum + hashmap approach → negatives pe bhi chlega.  
> Two pointer / Sliding window → only positive numbers pe chlega.

---

### Optimal — Two Pointer / Sliding Window (Positives Only)

```
arr = [1, 2, 3, 1, 1, 1, 1, 3, 3]
k = 6
```

- Right pointer aage badha, sum increase karo.
- Sum > k ho jaye → left se trim karo.
- Sum == k → length update karo.

```cpp
int left = 0, right = 0;
int sum = a[0];
int maxlen = 0;
int n = a.size();

while (right < n) {
    while (left <= right && sum > k) {
        sum -= a[left];
        left++;
    }
    if (sum == k) {
        maxlen = max(maxlen, right - left + 1);
    }
    right++;
    if (right < n) sum += a[right];
}
return maxlen;
```

- **TC:** O(2N) worst case — andar wala loop bhi total O(n) hi chalega
- **SC:** O(1)

---

## 11. Two Sum

```
arr = [2, 6, 5, 8, 11]  target = 14
→ indices: 1, 3  (6 + 8 = 14)
```

---

### Brute Force

```cpp
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        if (i == j) continue;
        if (arr[i] + arr[j] == target) return {i, j};
    }
}
```

- **TC:** O(n²)

---

### Better — Hashing

Iterate karo. Har element ke liye check karo ki `target - current` pehle se map mein hai ya nahi.

```cpp
map<int, int> mpp;
for (int i = 0; i < n; i++) {
    int a = nums[i];
    int more = target - a;
    if (mpp.find(more) != mpp.end()) {
        return "YES";
    }
    mpp[a] = i;
}
return "NO";
```

- **TC:** O(n) unordered_map avg, O(n log n) ordered map
- **SC:** O(n)

---

### Optimal — Two Pointer (Sort + Greedy)

> ⚠️ Agar indices return karni hain toh ye approach optimal nahi hai (sorting order bigaad deti hai). Sirf "Yes/No" ke liye best hai.

```
Sort the array.
left pointer at start, right pointer at end.
```

```cpp
int left = 0, right = n - 1;
sort();
while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) return "YES";
    else if (sum < target) left++;
    else right--;
}
return "NO";
```

- **TC:** O(n log n) for sorting + O(n)
- **SC:** O(n) for sorting

---

## 12. Sort an Array of 0s, 1s and 2s

```
x = [0, 1, 2, 0, 1, 2, 0, 0, 0, 1]
```

---

### Better — Count and Fill

Count karo, phir manually overwrite karo.

```cpp
int cnt0 = 0, cnt1 = 0, cnt2 = 0;
for (i = 0; i < n; i++) {
    if (a[i] == 0) cnt0++;
    else if (a[i] == 1) cnt1++;
    else cnt2++;
}
for (i = 0; i < cnt0; i++) a[i] = 0;
for (i = cnt0; i < cnt0 + cnt1; i++) a[i] = 1;
for (i = cnt0 + cnt1; i < n; i++) a[i] = 2;
```

- **TC:** O(2N)

---

### Most Optimal — Dutch National Flag Algorithm

**Three pointers:**
- `[0, low-1]` → 0s (extreme left)
- `[low, mid-1]` → 1s
- `[high+1, n-1]` → 2s (extreme right)
- `[mid, high]` → unsorted region

```
0 0 0 0 | 1 1 1 1 1 | ??? random ??? | 2 2 2 2 2
        low          mid              high
```

**Rules:**
- `a[mid] == 0` → swap with `a[low]`, `low++`, `mid++`
- `a[mid] == 1` → `mid++`
- `a[mid] == 2` → swap with `a[high]`, `high--` (mid nahi badhega)

```cpp
while (mid <= high) {
    if (arr[mid] == 0) {
        swap(arr[low], arr[mid]);
        low++;
        mid++;
    }
    else if (arr[mid] == 1) {
        mid++;
    }
    else {
        swap(arr[mid], arr[high]);
        high--;
    }
}
```

- **TC:** O(N) — mid se high tak, har step pe ek shrink hota hai
- **SC:** O(1)

---

## 13. Majority Element (Appears More Than n/2 Times)

```
arr[] = {2, 2, 3, 3, 1, 2, 2}
n = 7 → n/2 = 3
2 appears 4 times → answer: 2
```

---

### Brute Force — O(n²)

```cpp
for (i = 0; i < n; i++) {
    int count = 0;
    for (j = 0; j < n; j++) {
        if (arr[i] == arr[j]) count++;
    }
    if (count > n/2) return arr[i];
}
```

---

### Better — Hashing

```cpp
unordered_map<int, int> mp = {};
for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
}
for (auto it : mp) {
    if (it.second > n/2) {
        cout << it.first << endl;
        break;
    }
}
```

| Feature | `set` | `unordered_set` |
|---|---|---|
| Order | Sorted order | No order |
| Internal Structure | Red-Black Tree | Hash Table |
| Time Complexity | O(log n) | Average O(1) |
| Duplicate Allowed? | ❌ No | ❌ No |

- **TC:** O(n log n) ordered map, O(n) avg unordered
- **SC:** O(n)

---

### Optimal — Moore's Voting Algorithm

Two variables: `el` (candidate) and `cnt = 0`.

- `cnt == 0` → naya candidate lo, `cnt = 1`
- `v[i] == el` → `cnt++`
- `v[i] != el` → `cnt--`

**Intuition:** Jo majority element hai woh apne cancellations ke baad bhi positive count rakhega. Jo nahi hai woh kuch pal mein cancel ho jaayega.

**Step 1 — Find candidate:**

```cpp
int cnt = 0, el;
for (int i = 0; i < v.size(); i++) {
    if (cnt == 0) {
        cnt = 1;
        el = v[i];
    }
    else if (v[i] == el) {
        cnt++;
    }
    else {
        cnt--;
    }
}
```

**Step 2 — Verify:**

```cpp
int cnt = 0;
for (int i = 0; i < v.size(); i++) {
    if (v[i] == el) cnt++;
}
if (cnt > v.size() / 2) return el;
return -1;
```

- **TC:** O(N)
- **SC:** O(1)

---

## 14. Kadane's Algorithm — Maximum Subarray Sum

```
arr: [-2, -3, 4, -1, -2, 1, 5, -3]
→ max subarray sum: 7  (subarray: [4, -1, -2, 1, 5])
```

---

### Brute Force — O(n³)

```cpp
maxx = INT_MIN;
for (i = 0 → n):
    for (j = i → n):
        sum = 0
        for (k = i → j):
            sum += arr[k]
        maxx = max(sum, maxx)
```

---

### Better — O(n²)

Third loop hatao:

```cpp
for (i = 0 → n):
    sum = 0
    for (j = i → n):
        sum += arr[j]
        maxx = max(sum, maxx)
```

---

### Optimal — Kadane's Algorithm

**Key insight:** Agar sum negative ho jaye toh use aage mat le jaao. Sum = 0 karo aur fresh start karo.

```cpp
int maxi = INT_MIN;
int sum = 0;

for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum > maxi) {
        maxi = sum;
    }
    if (sum < 0) {
        sum = 0;
    }
}
```

**Kadane's in one line:** Ek aisi algorithm jo sum ko + karti hai, but sum ko tabhi aage le jaati hai jab sum -ve mein na ho. Agar -ve mein ho toh sum = 0 hota hai aur aage badhte hain.

**Printing the subarray:**

```cpp
int maxsubarraysum(int arr[], int n) {
    int maxi = INT_MIN, sum = 0;
    int start = 0, ansstart = -1, ansend = -1;

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i;
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            ansstart = start;
            ansend = i;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    // ansstart to ansend is the subarray
}
```

- **TC:** O(N)
- **SC:** O(1)

---

## 15. Best Time to Buy and Sell Stocks

```
arr[] = [7, 1, 5, 3, 6, 4]
buy: 1  sell: 6  profit: 5
```

Aim: profit maximize karo. Buying always before selling.

**Key insight:** Agar aap kisi din bech rahe ho toh us din se pehle minimum price pe kharido.

For each element track karo ki us moment tak ka minimum kya tha.

```
for 1: minimal is nothing
for 5: minimal is 1
for 3: minimal is 1
for 6: minimal is 1 → profit = 6 - 1 = 5
for 4: minimal is 1
```

```cpp
int mini = a[0];
int profit = 0;

for (int i = 1; i < n; i++) {
    int cost = a[i] - mini;    // sell - minimum (jispe kharida)
    profit = max(profit, cost);
    mini = min(mini, a[i]);    // track minimum
}
```

- **TC:** O(N)
- **SC:** O(1)

---

## 16. Rearrange Array Elements by Sign

```
arr: [3, 1, -2, -5, 2, -4]
→    [3, -2, 1, -5, 2, -4]
```

Equal positives and negatives diye hain. Pattern: `+-+-+-`

---

### Brute Force — Two Separate Arrays

```cpp
pos[], neg[] // n/2 size ke
// fill karo
for (i = 0; i < n/2; i++) {
    arr[2*i] = pos[i];
    arr[2*i + 1] = neg[i];
}
```

- **TC:** O(N)
- **SC:** O(N)

---

### Optimal — Direct Fill in New Array

```cpp
int n = nums.size();
vector<int> ans(n, 0);
int posindex = 0, negindex = 1;

for (int i = 0; i < n; i++) {
    if (nums[i] < 0) {
        ans[negindex] = nums[i];
        negindex += 2;
    }
    else {
        ans[posindex] = nums[i];
        posindex += 2;
    }
}
return ans;
```

- **TC:** O(N)
- **SC:** O(N)

---

### Variety 2 — Unequal Positives and Negatives

```
arr[] = [1, 2, -4, -5, 3, 6]
2 negative, 4 positive → +-+-+++
```

> Optimal approach yahan nahi chalega (pehle wala equal count pe based tha).  
> Brute force use karte hain.

```cpp
vector<int> alternateNumber(vector<int>& a) {
    vector<int> pos, neg;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }

    if (pos.size() > neg.size()) {
        for (int i = 0; i < neg.size(); i++) {
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++) {
            a[index] = pos[i];
            index++;
        }
    }
    else {
        // neg >= pos case (equal bhi yahi handle hoga)
        for (int i = 0; i < pos.size(); i++) {
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++) {
            a[index] = neg[i];
            index++;
        }
    }
    return a;
}
```

> Agar equal hain toh second loop chalega hi nahi (sizes equal hone pe leftover = 0).

- **TC:** O(2N)

---

## 17. Next Permutation

```
arr[] = [3, 1, 2]
```

All permutations in sorted order:
```
1 2 3 < 1 3 2 < 2 1 3 < 2 3 1 < 3 1 2 < 3 2 1
```

Question: `[3, 1, 2]` ka next permutation = `[3, 2, 1]`  
Agar `[3, 2, 1]` diya ho → no next → `[1, 2, 3]` (first wala)

---

### Brute Force — STL

```cpp
next_permutation(a.begin(), a.end());
return a;
```

---

### Optimal — Manual Implementation

**3 Observations:**

**Observation 1 — Find the breakpoint (pivot):**  
Right se traverse karo, woh index dhundho jahan `a[i] < a[i+1]` ho.

```
arr: 2 1 5 4 3 0 0
          ↑
     i=1 (a[1]=1 < a[2]=5) → breakpoint!
```

```cpp
int ind = -1;
for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
        ind = i;
        break;
    }
}
if (ind == -1) {
    reverse(arr);  // already last permutation, reverse to get first
}
```

**Observation 2 — Find smallest element > a[ind] from the right:**

```
arr: 2 1 5 4 3 0 0
     a[ind] = 1
     Right side mein: 5, 4, 3, 0, 0
     1 se bda aur sabse chota → 3
```

```cpp
for (int i = n - 1; i >= ind; i--) {
    if (arr[i] > arr[ind]) {
        swap(arr[i], arr[ind]);
        break;
    }
}
```

**Observation 3 — Reverse the suffix after ind:**

Swap ke baad `[ind+1, n-1]` decreasing order mein hoga → reverse karo to get smallest.

```cpp
reverse(arr, ind + 1, n - 1);
```

**Result:**
```
2 1 5 4 3 0 0
→ swap 1 and 3 → 2 3 5 4 1 0 0
→ reverse suffix → 2 3 0 0 1 4 5
```

- **TC:** O(N) + O(N) = O(2N)
- **SC:** O(1)

---

## 18. Product of Array Except Self

```
nums = [1, 2, 3, 4]
ans  = [24, 12, 8, 6]
```

`ans[i]` = product of all elements except `nums[i]`.

> ⚠️ Division method **not allowed**.

---

### Brute Force — O(n²)

```cpp
vector<int> ans(n, 1);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i != j) {
            ans[i] *= nums[j];
        }
    }
}
```

---

### Better — Prefix × Suffix

`ans[i] = prefix[i] * suffix[i]`

```
og array:  1  2  3  4
prefix:    1  1  2  6   (left product up to i, not including i)
suffix:   24 12  4  1   (right product from i, not including i)
ans:      24 12  8  6
```

```cpp
// prefix
for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] * nums[i-1];
}
// suffix
for (int i = n - 2; i >= 0; i--) {
    suff[i] = suff[i+1] * nums[i+1];
}
// ans
for (int i = 0; i < n; i++) {
    ans[i] = prefix[i] * suff[i];
}
```

- **TC:** O(3N)
- **SC:** O(N) do extra arrays

---

### Optimal — O(N) time, O(1) space

Prefix ko `ans` array mein hi calculate karo, phir backward loop mein suffix multiply karte jao.

```cpp
int n = nums.size();
vector<int> ans(n, 1);

// prefix fill in ans
for (int i = 1; i < n; i++) {
    ans[i] = ans[i-1] * nums[i-1];
}

// multiply suffix on the fly
int suffix = 1;
for (int i = n - 2; i >= 0; i--) {
    suffix = suffix * nums[i + 1];
    ans[i] *= suffix;
}
return ans;
```

- **TC:** O(N)
- **SC:** O(1) *(ans array ko output me count nahi karte)*

---

## 19. Leaders in an Array

```
arr: 10, 22, 12, 3, 0, 6
```

Leader = jiske right mein saare elements chote hain.

```
Leaders: [22, 12, 6]
```

> Last element humesha leader hota hai (kuch aage hai hi nahi).

---

### Brute Force — O(n²)

```cpp
for (i = 0 → n):
    leader = true
    for (j = i+1 → n):
        if (a[j] > a[i]):
            leader = false
            break
    if (leader == true) ans.push_back(a[i])
```

- **SC:** O(1) (no extra space used for solving)

---

### Optimal — O(N) — Backward Traversal

Piche se traverse karo. Max track karo. Jab bhi max milta hai → leader hai.

```cpp
vector<int> arr = {10, 22, 12, 3, 0, 6};
int n = arr.size();
vector<int> ans;
int maxx = -1;

for (int i = n - 1; i >= 0; i--) {
    if (arr[i] > maxx) {
        maxx = arr[i];
        ans.push_back(maxx);
    }
}

sort(ans.begin(), ans.end());
```

- **TC:** O(N) + O(N log N) for sort
- **SC:** O(1)

---

## 20. Longest Consecutive Sequence

```
arr[] = [100, 1, 2, 101, 103]
→ longest consecutive: 3  (100, 101, ??? actually 1,2,3 ?)
```

Array mein bikhere hue consecutive numbers dhundhne hain.

---

### Brute Force — O(n²)

Linear search: 100 ke liye 101 dhundho, mila toh 102 dhundho, etc.

```cpp
bool ls(vector<int> arr, int num) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) return true;
    }
    return false;
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    int maxl = 1;
    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i], len = 1;
        while (ls(arr, x + 1) == true) {
            x = x + 1;
            len = len + 1;
            maxl = max(len, maxl);
        }
    }
    cout << maxl;
}
```

- **TC:** O(n²)

---

### Better — Sort + Count

Sort karo, then traverse. Same elements skip karo, consecutive mile toh count badhaao.

```cpp
sort(arr.begin(), arr.end());
int small = INT_MIN, largest = 0, cnt = 0;

for (int i = 0; i < n; i++) {
    if (arr[i] > small) {
        if (arr[i] - 1 == small) {
            cnt = cnt + 1;
        }
        else {
            cnt = 1;
        }
        small = arr[i];
        largest = max(largest, cnt);
    }
    else if (arr[i] == small) {
        continue;  // ignore duplicate
    }
}
cout << largest;
```

- **TC:** O(n log n) for sort + O(N)

---

### Optimal — Unordered Set

Sorting se array disturb hoti hai. Set use karo.

**Key trick:** Sirf sequence ke **starting element** se count shuru karo. Starting element woh hai jiska `element - 1` set mein **nahi** hai.

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        int mcount = 0;

        if (arr.size() == 0) return 0;

        unordered_set<int> us;
        for (int it : arr) us.insert(it);

        for (int it : us) {
            if (us.find(it - 1) == us.end()) {
                // agar chota nahi hai tabhi hum aage jaana hai
                int cnt = 1;
                int x = it;
                while (us.find(x + 1) != us.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                mcount = max(mcount, cnt);
            }
        }
        return mcount;
    }
};
```

> Hum sirf sequence ke start se count karte hain, toh while loop kabhi O(n²) nahi banta — at max 2n total iterations.

- **TC:** O(N) for insert + O(N) for traversal = O(3N) total
- **SC:** O(N)

---

## 21. Set Matrix Zeroes

```
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1
```

Agar `matrix[i][j] == 0` toh poori i-th row aur j-th column ko 0 karo.

```cpp
int main() {
    vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
    for (auto row : m) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
}
```

---

### Brute Force — Mark as -1 First

> Directly 0 nahi kar sakte — isse naye zeros ban jayenge jo rows/columns ko galat se affect karenge.

Pehle -1 karo (0 wale elements ko chhodke), phir saare -1 ko 0 karo.

```
markrow(i) {
    for (j = 0; j < m; j++)
        if (arr[i][j] != 0) arr[i][j] = -1;
}
markcol(j) {
    for (i = 0; i < n; i++)
        if (arr[i][j] != 0) arr[i][j] = -1;
}

for (i = 0 → n):
    for (j = 0 → m):
        if (arr[i][j] == 0):
            markrow(i)
            markcol(j)

for (i = 0 → n):
    for (j = 0 → m):
        if (arr[i][j] == -1): arr[i][j] = 0
```

- **TC:** O(n*m) × O(n+m) + O(n*m) ≈ O(n³)

---

### Better — Extra Row/Column Arrays

Ek `row[n]` aur `col[m]` array lo. Jahan 0 mile, corresponding row aur col mark karo. Phir dubara iterate karo.

```
col[] = [0, 1, 0]  (mark which cols have zero)
row[] = [0, 1, 0]  (mark which rows have zero)
```

```cpp
for (i = 0 → n):
    for (j = 0 → m):
        if (arr[i][j] == 0):
            row[i] = 1
            col[j] = 1

for (i = 0 → n):
    for (j = 0 → m):
        if (row[i] == 1 || col[j] == 1):
            arr[i][j] = 0
```

- **TC:** O(2 × n*m)
- **SC:** O(N) + O(M) — do extra arrays

---

### Optimal — Use Matrix Itself (O(1) Space)

**Idea:** Row 0 ko column markers ki jagah use karo, Column 0 ko row markers ki jagah use karo.

**Problem:** `matrix[0][0]` dono (row 0 aur col 0) ke liye common ho jaata hai.

**Solution:** Column 0 ke liye ek alag `col0` variable lo.

```
col0 = 1 initially
matrix[i][0] → i-th row ka marker
matrix[0][j] → j-th column ka marker
```

**Step 1 — Mark:**

```cpp
int col0 = 1;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
            matrix[i][0] = 0;    // mark row
            if (j != 0) {
                matrix[0][j] = 0;    // mark col
            }
            else col0 = 0;    // 0th column has zero
        }
    }
}
```

**Step 2 — Update inner cells (1 to n-1, 1 to m-1):**

```cpp
for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
        if (matrix[i][j] != 0) {
            if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
}
```

**Step 3 — Handle first row (using matrix[0][0]):**

```cpp
if (matrix[0][0] == 0) {
    for (int j = 0; j < m; j++) matrix[0][j] = 0;
}
```

**Step 4 — Handle first column (using col0):**

```cpp
if (col0 == 0) {
    for (int i = 0; i < n; i++) matrix[i][0] = 0;
}
```

> **Order important hai:** Pehle inner cells → phir first row → phir first column.  
> Pehle first row ya column solve karne se `matrix[0][0]` ka value change ho sakta hai jo markers ko affect karega.

- **TC:** O(2 × n*m)
- **SC:** O(1)
