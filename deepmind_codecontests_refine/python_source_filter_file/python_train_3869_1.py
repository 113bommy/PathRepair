from collections import Counter

N = 10**5 + 10

n = int(input().lstrip())
colors = list(map(int, input().lstrip().split()))
cnt = Counter()
f = Counter()
mx = 0

for i, color in enumerate(colors):
    i += 1
    cnt[f[color]] -= 1
    f[color] += 1
    cnt[f[color]] += 1
    mx = max(mx, f[color])
    ok = False
    if (cnt[1] == i):  # every color has occurence of 1
        ok = True
    elif (cnt[i] == 1):  # All appeared colors in this streak
        # have the occurrence of 1(i.e. every color has exactly
        # 1 cat with that color).
        ok = True
    elif (cnt[1] == 1 and cnt[mx] * mx == i - 1):  # one color has
        # occurence of 1 and other colors have the same occurence
        ok = True
    elif (cnt[mx - 1] * (mx - 1) == i - mx and cnt[mx] == 1):  # one color
        # has the occurence 1 more than any other color
        ok = True
    if (ok):
        ans = i
    print(i, ans, mx, f[color], cnt, f, mx)
print(ans)