#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

n, k = map(int, input().split())
a = [-1 for i in range(n)]
c = 1

def merge(l, r, k):
    global c, a
    if l == r:
        return False
    k -= 1
    if k == 0:
        for i in range(l, r):
            a[i] = c
            c += 1
        return True
    if k == 1:
        return False
    m = l+(r-l)//2
    if (k//2)%2 == 1:
        if merge(m, r, k//2):
            return merge(l, m, k//2)
    else:
        if merge(m, r, k//2+1):
            return merge(l, m, k//2-1)
    return False
    
if not merge(0, n, k):
    print(-1)
    exit()
print(*a)