N, a, b = map(int, input().split()); a -= 1; b -= 1
P = []
Q = []
for i in range(N):
    x, y = map(int, input().split())
    P.append((x-y, x+y, i))
    Q.append((x+y, x-y, i))

d = max(abs(P[a][0] - P[b][0]), abs(P[a][1] - P[b][1]))

*parent, = range(N)
def root(x):
    if x == parent[x]:
        return x
    y = parent[x] = root(parent[x])
    return y
def unite(x, y):
    px = root(x); py = root(y)
    if px < py:
        parent[py] = px
    else:
        parent[px] = py
C = [0]*N
D = [0]*N

def check(P0, i0, j0):
    return abs(P0[i0][0] - P0[j0][0]) == abs(P0[i0][1] - P0[j0][1])

def solve(P0):
    P = P0[:]
    P.sort()

    s = t = 0; prev = -1
    for i in range(N):
        x, y, i0 = P[i]
        while t < N and P[t][0] < x-d or (P[t][0] == x-d and P[t][1] <= y+d): t += 1
        while s < N and (P[s][0] < x-d or (P[s][0] == x-d and P[s][1] < y-d)): s += 1
        if s < t:
            j0 = P[s][2]
            unite(i0, j0)
            if check(P0, i0, j0):
                D[i0] += 1
            else:
                C[i0] += 1
            if s < t-1:
                j0 = P[t-1][2]
                if check(P0, i0, j0):
                    D[i0] += 1
                    C[i0] += t-s-2
                else:
                    C[i0] += t-s-1
            for j in range(max(prev, s), t-1):
                unite(P[j][2], P[j+1][2])
            prev = t
solve(P)
solve(Q)

S = T = 0
r = root(a)
for i in range(N):
    if root(i) == r:
        S += C[i]; T += D[i]
print(S + T//2)
