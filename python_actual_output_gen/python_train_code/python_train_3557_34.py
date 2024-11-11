n, k = map(int, input().split())
out = - (10**10)
for _ in range(n):
    f,t = map(int, input().split())
    if t>k:
        z = f - (t-k)
    else:
        z = f
    out = min(out, z)
print(out)