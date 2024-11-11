import traceback
import math
from collections import defaultdict
from functools import lru_cache


def main():
    N = int(input())
    nums = input()
    # print(nums)
    locs = '31 00 01 02 10 11 12 20 21 22'.split()
    data = {str(k):(int(r), int(c)) for k,(r, c) in zip(range(10), locs)}

    dirs = []
    pr, pc = data[nums[0]]
    for n in nums[1:]:
        r, c = data[n]
        dr, dc = r - pr, c - pc
        dirs.append([dr, dc])
        pr, pc = r, c
    # print(dirs)
    for n in range(1, 10):
        n = str(n)
        if n == nums[0]: continue
        pr, pc = data[n]
        done = True
        for dr, dc in dirs:
            r, c = pr + dr, pc + dc
            if not ((r == 3 and c == 1) or (0 <= r < 3 and 0 <= c < 3)):
                done = False
                break
            pr, pc = r, c
        if done:
            return True
    return False


try:
    ans = main()
    ans = 'YES' if not ans else 'NO'
    print(ans)
except Exception as e:
    print(e)
    traceback.print_exc()