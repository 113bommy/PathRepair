N = int(input())
P = [None] + list(map(int, input().split()))

p_to_index = [None] * (N + 1)
for index, x in enumerate(P[1:], 1):
    p_to_index[x] = index


def BIT_add(i):
    while i <= N:
        tree[i] += 1
        i += i & (-i)

def BIT_sum(i):
    s = 0
    while i:
        s += tree[i]
        i -= i & (-i)
    return s

def BIT_search(x):
    i = 0
    s = 0
    step = 1 << (len(bin(N)[2:]) - 1)
    while step:
        if i + step <= N and s + tree[i + step] < x:
            i += step
            s += tree[i]
        step >>= 1
    return i + 1

tree = [0] * (N + 1)
ans = 0
for x in range(N, 0, -1):
    c = p_to_index[x]
    L = BIT_sum(c)
    R = N - x - L
    a = BIT_search(L - 1) if L >= 2 else 0
    b = BIT_search(L) if L >= 1 else 0
    d = BIT_search(L + 1) if R >= 1 else N + 1
    e = BIT_search(L + 2) if R >= 2 else N + 1
    BIT_add(c)
    tmp = 0
    if b != 0:
        tmp += (b - a) * (d - c)
    if d != 0:
        tmp += (e - d) * (c - b)
    ans += tmp * x

print (ans)