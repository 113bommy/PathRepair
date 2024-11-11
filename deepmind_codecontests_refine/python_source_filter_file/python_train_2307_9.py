#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7

def binleft(l, r, x):
    low = l
    high = r
    ans = None
    while low <= high:
        mid = (low+high)//2
        if 2*a[mid] < a[x]:
            ans = mid
            high = mid-1
        else:
            low = mid+1
    if 2*a[0] >= a[x]:
        ans = -1
    if ans is None: return 0
    return r-ans

def binright(l, r, x):
    low = l
    high = r
    ans = None
    while low <= high:
        mid = (low+high)//2
        if a[mid] <= 2*a[x]:
            ans = mid
            low = mid+1
        else:
            high = mid-1
    if ans is None: return 0
    return ans-x

n = int(input())
a = sorted(set(map(lambda x: abs(int(x)), input().split())))
n = len(a)
lr = [0 for i in range(n)]
rr = [0 for i in range(n)]
ans = 0

for i in range(n):
    ans += binright(i+1, n-1, i)

print(ans)