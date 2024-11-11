import sys
sys.setrecursionlimit(1500)

s1 = "What are you doing at the end of the world? Are you busy? Will you save us?"
a = "What are you doing while sending \""
b = "\"? Are you busy? Will you send \""
c = "\"?"
ans = ""


def solve(n, k):
    if n == 0:
        if k >= len(s1):
            return "."
        else:
            return s1[k]
    if k < len(a):
        return a[k]
    k -= len(a)
    prev_len = (2 ** (n - 1) - 1) * (len(a) + len(b) + len(c)) + (2 ** (n - 1)) * len(s1)
    if k < prev_len:
        return solve(n - 1, k)
    k -= prev_len
    if k < len(b):
        return b[k]
    k -= len(b)
    if k < prev_len:
        return solve(n - 1, k)
    k -= prev_len
    if k < len(c):
        return c[k]
    else:
        return "."


for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    k -= 1
    if n > 65:
        m = n - 65
        if k < len(a) * m:
            ans += a[(k - 1) % len(a)]
            continue
        k -= len(a) * m
        n = n - m
    ans += solve(n, k)

print(ans)
