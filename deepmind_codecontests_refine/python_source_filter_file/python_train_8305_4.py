N = int(input())
P = [int(a)-1 for a in input().split()]
INV = [0] * N
for i in range(N):
    INV[P[i]] = i

NN = 5
MA = [-1] * ((1<<NN+1)-1)
MI = [N] * ((1<<NN+1)-1)

def update(a, x):
    i = (1<<NN) - 1 + a
    MI[i] = x
    MA[i] = x
    while True:
        i = (i-1) // 2
        MI[i] = min(MI[2*i+1], MI[2*i+2])
        MA[i] = max(MA[2*i+1], MA[2*i+2])
        if i == 0:
            break

def rangemin(a, b):
    l = a + (1<<NN)
    r = b + (1<<NN)
    mi = N
    while l < r:
        if l%2:
            mi = min(mi, MI[l-1])
            l += 1
        if r%2:
            r -= 1
            mi = min(mi, MI[r-1])
        l >>= 1
        r >>= 1
    return mi
def rangemax(a, b):
    l = a + (1<<NN)
    r = b + (1<<NN)
    ma = -1
    while l < r:
        if l%2:
            ma = max(ma, MA[l-1])
            l += 1
        if r%2:
            r -= 1
            ma = max(ma, MA[r-1])
        l >>= 1
        r >>= 1
    return ma
ans = 0
for i in INV[::-1]:
    l1 = rangemax(0, i)
    l2 = rangemax(0, l1)
    r1 = rangemin(i+1, N+1)
    r2 = rangemin(r1+1,N+1)
    pre = ans
    ans += (P[i]+1) * ((i-l1) * (r2-r1) + (l1-l2) * (r1-i))
    update(i, i)

print(ans)