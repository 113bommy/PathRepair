S = input()
tmp = S[0]
now = ""
ans = 0
for i in range(len(S)):
    now += S[i]
    if tmp != now:
        ans += 1
        tmp = now
        now = ""
print(ans)
