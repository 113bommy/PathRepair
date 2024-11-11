rint = lambda: int(input())
rmint = lambda: map(int, input().split())
rlist = lambda: list(rmint())

n, k = rmint()
t = k
a = [0] * k
def no(): print("NO"); exit(0)
d = [-1] * (k+1); d[0] = 1
mx = 10 ** 9
for i in range(1, k+1):
    if d[i-1] * 2 > mx: break
    d[i] = d[i-1] * 2
for i in range(k):
    if n < 0: break
    if d[t] < 0:
        p = 1
        if i: p = a[i-1] + 1
    else:
        f = d[t] - 1
        p = max(1, (n + f - 1) // f)
    if i:
        p = max(p, a[i-1] + 1)
        p = min(p, a[i-1] * 2)
    a[i] = p
    t -= 1
    n -= p
if n: no()
print("YES")
for i in range(k): print(a[i],end=' ')
