import sys
from string import ascii_lowercase as lows

t = int(sys.stdin.readline())

def firstGreaterThan(nums, n):
    if nums[-1]<n:
        return nums[0]
    low = 0
    high = len(nums)-1
    mid = low
    while low!=high:
        mid = (low+high)//2
        if nums[mid] > n:
            high = mid
        else:
            low = mid+1
    return nums[low]

for _ in range(t):
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()
    s = list(zip(s, range(1,len(s)+1)))
    proc = {}
    for c in lows:
        at = list(filter(lambda x: x[0]==c, s))
        at = [tup[1] for tup in at]
        proc[c] = at
    at = 0
    revs = 1
    for c in t:
        if len(proc[c]) == 0:
            revs = -1
            break
        nex = firstGreaterThan(proc[c], at)
        if nex<=at:
            revs += 1
        at = nex
    print(revs)

