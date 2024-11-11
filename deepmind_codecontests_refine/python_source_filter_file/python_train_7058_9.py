from collections import deque

N = int(input())
X = [[] for i in range(N)]
Y = [-1] * N
for i in range(N-1):
    x, y = map(int, input().split())
    X[x-1].append(y-1)
    X[y-1].append(x-1)

C = sorted([int(a) for a in input().split()])[::-1]
print(sum(C)-max(C))

que = deque([0])
while que:
    i = deque.popleft(que)
    if Y[i] < 0:
        Y[i] = C.pop()
        for a in X[i]:
            deque.append(que, a)
print(*Y)