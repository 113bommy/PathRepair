import sys
input = sys.stdin.readline
n = int(input())
C = [list(map(int,input().split())) for i in range(n-1)]
m = int(input())
U = [list(map(int,input().split())) for i in range(m)]

for i in range(n-1):
    for j in range(2):
        C[i][j] -= 1
for i in range(m):
    for j in range(2):
        U[i][j] -= 1

B = [[0] * (m) for i in range(n-1)]

M = [[] for i in range(n)]
for i in range(n-1):
    M[C[i][0]].append([C[i][1], 1])  # 無向グラフなら両方追加
    M[C[i][1]].append([C[i][0], 1])  # 無向グラフなら両方追加

E = [[-1] * n for i in range(n)]
for i in range(n-1):
    E[C[i][0]][C[i][1]] = i
    E[C[i][1]][C[i][0]] = i  

F = [[] for i in range(m)]
import heapq

for mm in range(m):
    uu = U[mm][0]
    vv = U[mm][1]

    D = [float("inf")] * n  # 頂点0からの距離
    P = [-1] * n  # 頂点0からの最短距離において、そこの直前の頂点(経路復元に利用)
    D[uu] = 0
    V = [0] * n  # その頂点のD[i]が最短距離と確定したら1
    Q = []  # 優先度付きキュー
    for v in range(n):
        heapq.heappush(Q, [D[v], v])

    le = len(Q)
    while le > 0:
        q = heapq.heappop(Q)
        u = q[1]
        du = q[0]
        if V[u] == 0:
            V[u] = 1
            le -= 1
            for i in range(len(M[u])):
                v = M[u][i][0]
                luv = M[u][i][1]
                if V[v] == 0:
                    alt = du + luv
                    if D[v] > alt:
                        D[v] = alt
                        P[v] = u
                        heapq.heappush(Q, [alt, v])

    # print(P)
    tt = vv
    while tt != uu:
        ss = P[tt]
        F[mm].append(E[ss][tt])
        print(ss,tt)
        tt = ss

print("F",F)

for i in range(m):
    for j in F[i]:
        B[j][i] = 1



M2 = [1]
for i in range(30):
    M2.append(M2[-1]*2)

# B.sort(key=lambda x:sum(x))

BB = [[] for i in range(m+1)]
for i in range(len(B)):
    BB[sum(B[i])].append(B[i][:])
# print(BB)
CC = []
for i in range(len(BB)):
    for j in range(len(BB[i])):
        CC.append(BB[i][j])
B=CC
import itertools
# print("B",B)
G = [0] * (2**m)
G[0] = 1
for i in range(n-1):
    ii = 0
    K = []
    for j in range(m):
        if B[i][j] == 1:
            K.append(j)
        ii += B[i][j] * M2[m-1-j]
    # print(ii)

    GG = G[:]
    for jj in range(2**m):
        GG[jj | ii] += G[jj]
    G = GG[:]
    # print("K",K)
    # for jj in range(len(K), -1, -1):
    #     TT = list(itertools.combinations(K, jj))
    #     print(jj,TT)
    #     for j in range(len(TT)):
    #         tt = 0
    #         for bb in range(len(TT[j])):
    #             tt += M2[m-1-TT[j][bb]]
    #         print("tt",tt)
    #         G[ii] += G[tt]
    #         G[tt] += G[tt]
    # print("G",G)

print(G[-1])




# M = [[] for i in range(n)]
# for i in range(n-1):
#     M[A[i][0]].append([A[i][1], i])
#     M[A[i][1]].append([A[i][0], i])

# for i in range(m):
#     ok = 0
#     u = U[i][0]
#     v = U[i][1]
#     Q = [u]
#     E = []
#     V = [0] * n
#     V[u] = 1
#     while len(Q) > 0:
#         qq = Q.pop()
#         t = 0
#         for j in M[qq]:
#             jj = j[0]
#             if V[jj] == 0:
#                 t = 1
#                 V[jj] = 1
#                 Q.append(jj)
#                 E.append(j[1])
#                 if jj == v:
#                     ok = 1
#                     break
#         if ok == 1:
#             break
#         if t == 0:
#             ee = E.pop()
