n, k = map(int, input().split())
p = list(map(int, input().split()))
c = list(map(int, input().split()))


for i in range(n):
    p[i] -= 1

def score(a, k):
    now = p[a]
    s = c[now]
    cnt = 1
    ans = s
    while now != a and cnt < k:
        now = p[now]
        s += c[now]
        ans = max(ans, s)
        cnt += 1
    if cnt == k:
        return ans
    if k % cnt == 0:
        return (k // cnt - 1) * s + ans
    s = (k // cnt) * s
    k %= cnt
    cnt = 0
    while cnt < k:
        now = p[now]
        s += c[now]
        ans = max(ans, s)
        cnt += 1
    return ans

print(max(score(i, k) for i in range(n)))
