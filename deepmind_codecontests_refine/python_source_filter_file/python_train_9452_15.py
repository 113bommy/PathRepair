import sys
input = sys.stdin.readline

N, M, P = map(int, input().split())

INF = 10 ** 9
#入力

# 入力は1-index
# 内部で0-indexにして処理
G = []
for _ in range(M): #M個の辺の情報を受け取る
    A, B, C = map(int, input().split()) #lからrへ重みsの辺が存在
    G += [[A - 1, B - 1, P - C]] #有向グラフのときはここだけ

check = [False] * N
d = [INF] * N #距離を記録

def shortest_path(s): #S番目の頂点から各頂点への最短距離を求める
    s -= 1
    d[s] = 0
    i = 0
    while i < N - 1:
        for i in range(M): #無向グラフのときは辺は実質的には2倍
            e = G[i]
            if d[e[0]] != INF and d[e[1]] > d[e[0]] + e[2]:
                d[e[1]] = d[e[0]] + e[2]
        i += 1
    
    j = 0
    while j < N:
        for i in range(M):
            e = G[i]
            if d[e[0]] == INF:
                continue
            if d[e[0]] != INF and d[e[1]] > d[e[0]] + e[2]:
                d[e[1]] = d[e[0]] + e[2]
                check[e[1]] = True
            if check[e[0]]:
                check[e[1]] = True
        j += 1

shortest_path(1)
if check[N - 1]:
    print (-1)
else:
    ans = d[N - 1]
    print (max(0, -ans))
# print (d)