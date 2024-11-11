import string
import bisect
S = input()
T = input()
n = len(S)
sa = {_: [] for _ in string.ascii_lowercase}
for i, s in enumerate(S):
    sa[s] += [i]
ans = 0
i = -1
for t in T:
    if sa[t]:
        j = bisect.bisect_left(sa[t], i)
        if j == len(sa[t]):
            ni = sa[t][0] + n
        else:
            ni = sa[t][j]
        ans += ni - i
        i = ni % n
    else:
        print(-1)
        exit()
print(ans)
