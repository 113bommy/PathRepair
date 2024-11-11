import sys
input = sys.stdin.readline
S = input().strip()
mod = 10**9+7
a = 0
ab = 0
ans = 0
q = 1
for c in S:
    if c == 'A':
        a += q
    elif c == 'B':
        ab += a
    elif c == 'C':
        ans += ab
    elif c == '?':
        a, ab, ans, q = a*3+q, ab*3+a, ans*3+ab, q*3
    #a %= mod
    #ab %= mod
    #ans %= mod
    #q %= mod
print(ans % mod)
