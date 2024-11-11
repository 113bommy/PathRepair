import traceback
import math
from collections import defaultdict
from functools import lru_cache


def main():    
    N = int(input())
    nums = list(map(int, input().split()))
    for i in range(1,N):
        nums[i] += nums[i-1]
    lo, hi = 0, N-1
    val = math.ceil(nums[-1] // 2)
    while lo < hi:
        mid = (lo + hi) // 2
        if nums[mid] >= val:
            hi = mid
        else:
            lo = mid + 1
    return lo + 1


try:
    ans = main()
    print(ans)
except Exception as e:
    print(e)
    traceback.print_exc()