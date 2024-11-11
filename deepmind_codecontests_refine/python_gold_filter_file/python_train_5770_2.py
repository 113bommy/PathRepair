n, k, l, r, s, sk = (int(s) for s in input().split())

a = [l] * n
s -= l * n
sk -= l * k

for i in range(k):
    a[i] += sk // k
for i in range(sk % k):
    a[i] += 1

if k < n:
    sr = s - sk
    for i in range(k, n):
        a[i] += sr // (n - k)
    for i in range(sr % (n - k)):
        a[k + i] += 1

print(' '.join(str(i) for i in a))
