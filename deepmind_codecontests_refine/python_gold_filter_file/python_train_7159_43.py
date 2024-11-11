import sys
input = sys.stdin.readline
n, q = map(int, input().split())
c = list(map(lambda x: int(x) - 1, input().split()))
query = []
for i in range(q):
    l, r = map(lambda x: int(x) - 1, input().split())
    query.append(l << 40 | r << 20 | i)

query.sort()
ball = [list() for i in range(n)]
for i, x in enumerate(c):
    ball[x].append(i)

# binary indexed tree
bit = [0] * (n + 1)
def add(i, x):
    i += 1
    while i <= n:
        bit[i] += x
        i += i & -i

def get(i):
    i += 1
    s = 0
    while i:
        s += bit[i]
        i -= i & -i
    return s

for i in ball:
    if i:
        add(i[0], 1)
        i.reverse()

at = 0
ans = [0] * q
for x in query:
    l = x >> 40
    r = x >> 20 & 0xfffff
    i = x & 0xfffff
    while at < l:
        b = ball[c[at]]
        add(b[-1], -1)
        b.pop()
        if b:
            add(b[-1], 1)
        at += 1
    ans[i] = get(r) - get(l - 1)

for i in ans:
    print(i)