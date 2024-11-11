from collections import defaultdict
import sys

sys.setrecursionlimit(500005)
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

n = ni()
ss = []
cs = []
for i in range(n):
    s, c = stdin.readline().split()
    ss.append(s)
    cs.append(int(c))

dp = defaultdict(lambda: 999999999999999)
rdp = defaultdict(lambda: 999999999999999)
p = 0
ved = set()
for s in ss:
    dp[s] = min(dp[s], cs[p])
    p += 1
    ved.add(s)

ans = 999999999999999

while True:
    dpp = defaultdict(lambda: 999999999999999)
    rdpp = defaultdict(lambda: 999999999999999)
    for k, v in dp.items():
        if k == k[::-1]:
            ans = min(ans, v)
        else:
            p = 0
            for s in ss:
                if k.startswith(s[::-1]):
                    ns = k[len(s):]
                    if v + cs[p] < dp.get(ns, 99999999999999):
                        dpp[ns] = min(dpp[ns], v + cs[p])
                elif s[::-1].startswith(k):
                    ns = s[::-1][len(k):]
                    if v + cs[p] < rdp.get(ns, 99999999999999):
                        rdpp[ns] = min(rdpp[ns], v + cs[p])
                p += 1
    for k, v in rdp.items():
        if k == k[::-1]:
            ans = min(ans, v)
        else:
            p = 0
            for s in ss:
                if k.startswith(s):
                    ns = k[len(s):]
                    if v + cs[p] < rdp.get(ns, 999999999999999):
                        rdpp[ns] = min(rdpp[ns], v + cs[p])
                elif s.startswith(k):
                    ns = s[len(k):]
                    if v + cs[p] < dp.get(ns, 999999999999999):
                        dpp[ns] = min(dpp[ns], v + cs[p])
                p += 1
    if len(dpp) + len(rdpp) == 0:
        break
    for k, v in dpp.items(): dp[k] = v
    for k, v in rdpp.items(): rdp[k] = v
print(ans if ans < 999999999999999 else -1)
