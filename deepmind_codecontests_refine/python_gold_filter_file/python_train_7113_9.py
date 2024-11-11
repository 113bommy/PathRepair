def f(v, k):
    val, d = 0, 1
    while d <= v:
        val += v // d
        d *= k
    return val

n, k = map(int, input().split())
v1, v2 = 0, n
while v1 < v2 - 1:
    nxt = (v1 + v2) // 2
    if f(nxt, k) < n:
        v1 = nxt
    else:
        v2 = nxt
print(v2)