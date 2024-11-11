import sys
sys.setrecursionlimit(int(1e6))

s = input()
t = input()

len_s = len(s)
set_s = set(s)
set_t = set(t)

if len(set_t - set_s) != 0:
    print(-1)
    sys.exit()

n = {}
ss = s + s
ans = 0
for c in t:
    i = ans % len_s
    if not c in n:
        n[c] = [0] * len_s
    if n[c][i] == 0:
        n[c][i] = ss[i:].find(c) + 1
    ans += n[c][i]

print(ans)
