n = int(input())

L = [int(x)-1 for x in input().split()]

V = [int(x) for x in input().split()]

G = []
DG = []
VD = []
VU = []
for i in range(n):
    G.append([])
    DG.append([])
    VD.append([])
    VU.append([])


for i in range(n-1):
    DG[L[i]].append(i+1)
    G[i+1].append(L[i])
    G[L[i]].append(i+1)

for i in range(n):
    for j in DG[i]:
        if V[j] != -1:
            VD[i].append(V[j])

for i in range(1,n):
    if V[L[i-1]] != -1:
        VU[i].append(V[L[i-1]])


depth = [0]*n
values = [0]*n
s = 1
depth[0] = 1
q = DG[0][:]
values[0] = 1
bad = False
while q:
    v = q.pop()
    q.extend(DG[v])
    depth[v] = 1-depth[L[v-1]]
    if depth[v] == 1:
        values[v] = V[v]
        s += values[v]-values[L[v-1]]
        if values[v]-values[L[v-1]] < 0:
            bad = True
    else:
        if len(DG[v]) == 0:
            values[v] = 0
        else:
            values[v] = min(V[i] for i in DG[v])
            s += values[v]-values[L[v-1]]
            if values[v]-values[L[v-1]] <0:
                bad = True
if bad:
    print(-1)
else:
    print(s)