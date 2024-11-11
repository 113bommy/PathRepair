s = list(input())
k = int(input())
x = []
ans = 0
cnt = 1
for i in range(len(s)):
    if i < len(s) - 1 and s[i] == s[i + 1]:
        cnt += 1
    else:
        ans += cnt // 2
        x.append(cnt)
        cnt = 1
cnt = 0
if s[0] == s[len(s) - 1]:
    cnt = x[0] // 2 + x[-1] // 2 - (x[0] + x[1]) // 2

print(ans * k - cnt * (k - 1) if len(set(s)) != 1 else len(s) * k // 2)