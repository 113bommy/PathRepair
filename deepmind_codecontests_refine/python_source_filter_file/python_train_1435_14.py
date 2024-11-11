from collections import deque
N, M = map(int, input().split())
X = [[] for x in range(N+1)]
for m in range(M):
    A, B = map(int, input().split())
    X[A].append(B)
    X[B].append(A)

Q = deque()
Q.append(1)

D = [-1]*(N+1)
D[0] = 0
D[1] = 0
while Q:
    v = Q.pop()
    for i in X[v]:
        if D[i] == -1:
            D[i] = i
            Q.appendleft(i)
if -1 in D:
    print('No')
else:
    print('Yes')
    print(*D[2:])