# C
from collections import deque

N, M = map(int, input().split())
s = list(input())
s_ = []
for c in s:
    s_.append(c)

# Graph
G = dict()
for i in range(1, N+1):
    G[i] = dict()

for _ in range(M):
    a, b = map(int, input().split())
    G[a][b] = 1
    G[b][a] = 1
    
# clean up
queue = deque()
go = True

As = [0]*N
Bs = [0]*N

for i in range(1, N+1):
    if s[i-1] != "C":
        a = 0
        b = 0
        for k in G[i].keys():
            v = s[k-1]
            if v == "A":
                a += 1
            elif v == "B":
                b += 1
        As[i-1] = a
        Bs[i-1] = b
        if a*b == 0:
            queue.append(i)
            s[i-1] = "C"

while len(queue) > 0:
    j = queue.popleft()
    for i in G[j].keys():
        if s[i-1] != "C":
            if s_[j-1] == "A":
                As[i-1] -= 1
            else:
                Bs[i-1] -= 1
            if As[i-1] * Bs[i-1] == 0:
                queue.append(i)
                s[i-1] = "C"

if "A" in s and "B" in s:
    print("Yes")
else:
    print("No")