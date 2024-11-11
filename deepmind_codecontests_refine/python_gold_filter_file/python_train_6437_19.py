s = input()

i_flips = []
i = 0
for j in range(1, len(s)):
    if s[j] != s[i]:
        i_flips.append(j)
        i = j
# print(i_flips)

if len(i_flips) == 0:
    print(len(s))
else:
    ans = len(s)
    for i in i_flips:
        ans = min(ans, max(i, len(s)-i))
    print(ans)
