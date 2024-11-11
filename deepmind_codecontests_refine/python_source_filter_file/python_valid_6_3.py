import sys;input=sys.stdin.readline
N, M = map(int, input().split())

X = [0]*(N+1)
R = 0
for i in range(M):
    u, v = map(int, input().split())
    if X[min(u, v)] == 0:
        R += 1
    X[min(u, v)] += 1
Q, = map(int, input().split())
for j in range(Q):
    s = input().strip()
    if s[0] == "1":
        _,u,v=map(int, s.split())
        if X[min(u, v)] == 0:
            R += 1
        X[min(u, v)] += 1
    elif s[0] == "2":
        _,u,v=map(int, s.split())
        if X[min(u, v)] == 1:
            R -= 1
        X[min(u, v)] += 1
    else:
        print(N-R)



