import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
a = [None]*(n-1)
from collections import defaultdict
c = defaultdict(list)
for i in range(n-1):
    num = int(input())
    c[num].append(i+2)

def sub(winner):
    l = len(c[winner])
    vs = []
    for p in c[winner]:
        vs.append(sub(p))
    vs.sort()
    ans = l
    for i,v in enumerate(vs):
        ans = max(ans, l-(i)+v)
#     print(winner, ans, l, vs)
    return ans
ans = sub(1)
print(ans)