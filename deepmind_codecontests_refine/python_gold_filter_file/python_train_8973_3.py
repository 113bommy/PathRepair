#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue, collections
MOD = 10**9+7
#sys.stdin = open('input.txt', 'r')

def left_border(a, r):
    ans = -10**10
    l, h = 0, len(a)-1
    while l <= h:
        m = (l+h)//2
        if a[m] <= r:
            ans = a[m]
            l = m+1
        else:
            h = m-1
    return ans

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ps = [0 for i in range(2*n)]
    pb = [0 for i in range(2*n)]
    v = {0: [-1]}
    for i in range(2*n):
        ps[i] += ps[i-1]
        pb[i] += pb[i-1]
        
        if a[i] == 1:
            ps[i] += 1
        else:
            pb[i] += 1
        
        if i >= n:
            continue

        d = ps[i]-pb[i]
        if d in v:
            v[d].append(i)
        else:
            v[d] = [i]

    ans = 2*n
    for i in range(n-1, 2*n):
        d = (ps[i]-pb[i])-(ps[-1]-pb[-1])
        if d not in v:
            continue
        ans = min(ans, i-left_border(v[d], i))
    print(ans)