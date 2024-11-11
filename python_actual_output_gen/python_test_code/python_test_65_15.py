n = int(input())
s = input() + '2'
ans = 1
cur = Max = j = 0
flag = False
cnt2 = 0
for i in range(1, n + 1):
    if s[i] != s[j]:
        j = i
        if s[i] != '2': ans += 1
        if cur >= 3: flag = True
        elif cur >= 2: cnt2 += 1
        cur = 0
    cur += 1
if flag or cnt2 >= 2: ans += 2
elif cnt2 == 1: ans += 1
print(ans)
