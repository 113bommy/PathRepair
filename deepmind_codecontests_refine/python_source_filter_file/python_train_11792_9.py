import io
import os
import sys
from collections import deque, defaultdict
from itertools import accumulate


def _input():
    x = sys.stdin.readline()
    x = x.replace('\r', '')
    x = x.replace('\n', '')
    return x


if 'STDINPUT' not in os.environ:
    input = _input
else:
    print('Standard input')


def solve():
    n, k = [int(x) for x in input().split()]
    l1, r1 = [int(x) for x in input().split()]
    l2, r2 = [int(x) for x in input().split()]
    if r1 - l1 < r2 - l2:
        l1, r1, l2, r2 = l2, r2, l1, r1
    complete = max(r1, r2) - min(l1, l2)
    intersection = 0
    step = None
    if l2 > l1 and r2 < r1:
        step = l2 - l1 + r1 - r2
        intersection = r2 - l2
    elif l1 > l2 and r1 < r2:
        step = l1 - l2 + r2 - r1
        intersection = r1 - l1
    elif l1 < l2:
        step = l2 - l1 + r2 - r1
        intersection = max(0, r1 - l2)
    else:
        step = l1 - l2 + r1 - r2
        intersection = max(0, r2 - l1)
    
    k -= intersection * n
    complete -= intersection
    ans = 0
    done = 0
    while k >= complete and done < n:
        k -= complete
        ans += step
        done += 1
    if k <= 0:
        print(ans)
    else:
        if done == n:
            print(ans + 2 * k)
        else:
            if l1 < l2:
                initial = r1 - l2
            else:
                initial = r2 - l1
            print(min(ans + k - min(0, initial), (ans + 2 * k if done > 1 else 10 ** 10)))



test_cases = True
if test_cases:
    _q = int(input())
    for _ in range(_q):
        solve()
else:
    solve()
