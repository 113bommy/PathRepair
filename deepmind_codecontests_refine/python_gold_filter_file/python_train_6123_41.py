#EDPC P_Independent_Set
import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 7)
 
N = int(input())
edge = [[] for _ in range(N + 1)]
mod = 10 ** 9 + 7
 
for _ in range(N - 1):
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

root = 1
 
black = [1] * (N + 1)
white = [1] * (N + 1)
under = [[] for _ in range(N+1)]
seen = [False] * (N + 1)

#節点iの子のリストを作成
node = [root]
while node:
    s = node.pop()
    seen[s] = True
    for t in edge[s]:
        if seen[t]:
            continue
        node.append(t)
        under[s].append(t)

def BW(s):
    if not under[s]: #葉なら白黒1色ずつ
        return
    for t in under[s]:
        BW(t)
        white[s] = (white[s] * (white[t] + black[t])) % mod
        black[s] = (black[s] * white[t]) % mod

BW(root)
ans = white[root]+black[root]
print(ans%mod)
    
 

