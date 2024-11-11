import string
import bisect

S, T = input(), input()
lS, lT = len(S), len(T)

l = {s: [] for s in string.ascii_lowercase}
for i in range(lS):
    l[S[i]].append(i)

id, ans = 0, 0
for i in range(lT):
    if len(l[T[i]]) == 0:
        print(-1)
        exit()
    else:
        tmp = l[T[i]][(bisect.bisect(l[T[i]], id)) % len(l[T[i]])]
        if id >= tmp:
            ans += lS
        id = tmp

print(ans + id + 1)
