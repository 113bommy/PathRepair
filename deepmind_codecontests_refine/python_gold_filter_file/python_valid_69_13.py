import math
from collections import Counter
from functools import lru_cache

t = int(input())
for _ in range(t):
    arr = input()
    powers = [1]
    start = 1
    for i in range(1, 60):
        start *= 2
        powers.append(start)
    ans = len(arr)+1
    for i in powers:
        s = str(i)
        common = 0
        for j in range(len(arr)):
            count = 0
            k = 0
            ind = 0
            while j+k < len(arr) and ind < len(s):
                if arr[j + k] == s[ind]:
                    ind += 1
                    count += 1
                k += 1
            common = max(common, count)
        temp = len(arr)-common
        temp += len(s) - common
        ans = min(ans, temp)
    print(ans)
