import sys
input = sys.stdin.readline

def make_tree(n):
    i = 2
    while True:
        if i >= n * 2:
            tree = [0] * i
            break
        else:
            i *= 2
    return tree

def update(i, x):
    i += len(tree) // 2
    tree[i] = x
    i //= 2
    while True:
        if i == 0:
            break
        tree[i] = tree[2 * i] + tree[2 * i + 1]
        i //= 2
    return

def get_sum(s, t):
    s += len(tree) // 2
    t += len(tree) // 2
    ans = 0
    while True:
        if s > t:
            break
        if s % 2 == 0:
            s //= 2
        else:
            ans += tree[s]
            s = (s + 1) // 2
        if t % 2 == 1:
            t //= 2
        else:
            ans += tree[t]
            t = (t - 1) // 2
    return ans

n = int(input())
mod = 998244353
s = [0] * n
xy = []
z = []
d = dict()
for i in range(n):
    x, y, s0 = map(int, input().split())
    s[i] = s0
    xy.append((x, y))
    z.append(x)
    z.append(y)
z.sort()
for i in range(2 * n):
    d[z[i]] = i + 1
tree = make_tree(2 * n + 5)
ans = x + 1
for i in range(n):
    x, y = xy[i]
    dx, dy = d[x], d[y]
    d0 = x - y
    c = get_sum(dy, dx)
    cd = (c + d0) % mod
    if s[i]:
        ans += cd
        ans %= mod
    update(dx, cd)
print(ans)