import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


from collections import defaultdict
n,m = map(int, input().split())
ns = defaultdict(set)
for _ in range(n-1):
    u,v = map(int, input().split())
    u -= 1
    v -= 1
    ns[u].add(v)
    ns[v].add(u)
s = 0
for t in ns[s]:
    break
l = set([s,t])
from queue import deque
ans = deque([s,t])
while True:
    if not all(u in l for u in ns[s]):
        for u in ns[s]:
            if u not in l:
                break
        ans.appendleft(u)
        l.add(u)
        s = u
    elif not all(v in l for v in ns[t]):
        for v in ns[t]:
            if v not in l:
                break
        ans.append(v)
        l.add(v)
        t = v
    else:
        break
print(len(ans))
write(" ".join(map(lambda x: str(x+1), ans)))