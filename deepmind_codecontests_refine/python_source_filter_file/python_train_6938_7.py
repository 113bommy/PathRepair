#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

N = 31624

for _ in range(int(input())):
    x = int(input())
    found = None
    for i in range(1, N):
        if i*i-x <= 0: continue
        low, high = 1, N-1
        while low <= high:
            mid = (low+high)>>1
            lhs = i*i - (i//mid)*(i//mid)
            if lhs == x:
                found = (i, mid)
                break
            elif lhs < x:
                low = mid+1
            else:
                high = mid-1
        if found is not None:
            break
    if found is None: print(-1)
    else: print(*found)