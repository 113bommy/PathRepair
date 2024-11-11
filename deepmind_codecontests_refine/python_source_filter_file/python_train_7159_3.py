BIT = [0] * ((1 << 19) + 1)
def add(i, x):
    while i <= (1 << 19):
        BIT[i] += x
        i += i & (-i)
def query(i):
    res = 0
    while i > 0:
        res += BIT[i]
        i -= i & (-i)
    return res
n, q = map(int, input().split())
c = list(map(int, input().split()))
Q = [[] for i in range(n)]
for i in range(q):
    l, r = map(int, input().split())
    Q[r - 1].append([l - 1, i])
l = [-1] * n
a = [-1] * q
add(1, n)
for i in range(n):
    add(l[c[i] - 1] + 2, -1)
    add(i + 2, 1)
    l[c[i] - 1] = i
    for j in Q[i]:
        a[j[1]] = query(1 << 19) - query(j[0] + 1)
print(*a, sep="\n")