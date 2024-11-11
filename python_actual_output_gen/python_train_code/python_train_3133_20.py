n, p = map(int, input().split())
s = list(map(int, input()))
ans = 0

if p == 2 or p == 5:
    for i, x in enumerate(s):
        if (p == 2 and not x % 2) or (p == 5 and (x == 0 or x == 5)):
            ans += i+1
    print(ans)
    exit()

s.reverse()
cum = [0] * (n+1)
for i in range(n):
    cum[i+1] = (cum[i] + s[i] * pow(10, i, p)) % p
t = [0] * 10
for x in cum: t[x] += 1

for x in t:
    ans += x * (x-1) // 2
print(ans)
