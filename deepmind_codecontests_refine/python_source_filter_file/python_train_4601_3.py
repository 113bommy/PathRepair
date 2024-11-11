import sys
input = sys.stdin.readline

Q = int(input())
for _ in range(Q):
    N = int(input())
    X = []
    ne = [0] * 3
    for i in range(N):
        a, b = map(int, input().split())
        X.append((a, b))
        if i == 0:
            ne = [0, b, b*2]
            continue
        Y = ne
        ne = [1<<30] * 3
        if X[i][0] != X[i-1][0]: ne[0] = min(ne[0], Y[0])
        if X[i][0] != X[i-1][0]+1: ne[0] = min(ne[0], Y[1])
        if X[i][0] != X[i-1][0]+2: ne[0] = min(ne[0], Y[2])
        if X[i][0]+1 != X[i-1][0]: ne[1] = min(ne[1], Y[0] + b)
        if X[i][0]+1 != X[i-1][0]+1: ne[1] = min(ne[1], Y[1] + b)
        if X[i][0]+1 != X[i-1][0]+2: ne[1] = min(ne[1], Y[2] + b)
        if X[i][0]+2 != X[i-1][0]: ne[2] = min(ne[2], Y[0] + b * 2)
        if X[i][0]+2 != X[i-1][0]+1: ne[2] = min(ne[2], Y[1] + b * 2)
        if X[i][0]+2 != X[i-1][0]+2: ne[2] = min(ne[2], Y[2] + b * 2)
        
    print(min(ne))
