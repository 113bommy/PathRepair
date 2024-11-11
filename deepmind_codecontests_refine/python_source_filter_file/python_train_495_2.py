n = int(input())
x = list(map(int, input().split()))
mod = 10**9 + 7
X = []
for i in range(n - 1):
    X.append(x[i + 1] - x[i])
l, left = 1, [1]
for i in range(1, n - 1):
    l *= i
    l %= mod
    left.append(l)
r, right = 1, [1]
for i in range(n - 1, 1, -1):
    r *= i % mod
    right.append(r)
right.reverse()
f, flst = 0, []

for i, j in zip(left, right):
    f += i * j % mod
    f %= mod
    flst.append(f)
s = 0
for i, j in zip(X, flst):
    s += i * j % mod
print(s % mod)
