def cmp(s1, s2):
    ans = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            ans += 1
    return ans


n, m, k = map(int, input().split())
P = [bin(int(input()))[2:].rjust(n, "0") for i in range(m)]
Feda = bin(int(input()))[2:].rjust(n, "0")
ans = 0
for a in P:
    if cmp(Feda, a) <= k:
        ans += 1
print(ans)