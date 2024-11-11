s = input()
t = input()

n = len(s)
m = len(t)

t = t + '$' + s

p = [0] * (n + m + 1)
k = 0
for i in range(1, n + m + 1):
    while k > 0 and t[k] != t[i]:
        k = p[k - 1]
    if t[k] == t[i]:
        k += 1
    p[i] = k

ans = [0] * n
sums = [0] * (n + 1)
curs = 0
was = False
j = 0
MOD = 10 ** 9 + 7
for i in range(n):
    if p[i + m + 1] == m:
        if not was:
            was = True
            curs = 1
        while j <= i - m:
            curs = (curs + sums[j] + 1) % MOD
            j += 1
    ans[i] = curs
    sums[i] = (sums[i - 1] + ans[i]) % MOD

print(sum(ans))
