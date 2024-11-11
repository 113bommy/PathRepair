def count(x):
    if x <= 1:
        return 1
    return count(x >> 1) * 2 + 1

def f(n, l, r):
    if l > r:
        return 0
    if n <= 1:
        return n
    cnt = count(n >> 1)
    res = 0
    res += f(n >> 1, l, min(r, cnt))
    if r >= cnt + 1:
        res += n & 1
    res += f(n >> 1, max(1, l - cnt - 1), r - cnt - 1)
    return res
    

n, l, r = map(int, input().split())
print(f(n, l, r))