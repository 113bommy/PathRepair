# seishin.py
N = int(input())
*A, = map(int, input().split())

def solve(x):
    data = [0]*(N+1)
    def add(k, x):
        while k <= N:
            data[k] += x
            k += k & -k
    def get(k):
        s = 0
        while k:
            s += data[k]
            k -= k & -k
        return s
    c = 0; d = 10**18
    for a in A:
        if x <= a:
            c += 1
        else:
            c -= 1
        d = min(c, d)
    res = N*(N+1)//2
    c = -d+1
    for a in A:
        res -= get(c)
        if x <= a:
            c += 1
        else:
            c -= 1
        add(c, 1)
    return res <= N*(N+1)//4

left = min(A); right = max(A)+1
while left+1 < right:
    mid = (left + right) // 2
    if solve(mid):
        left = mid
    else:
        right = mid
print(left)
