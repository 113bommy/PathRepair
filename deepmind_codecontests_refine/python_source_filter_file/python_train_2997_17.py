from collections import deque

K = int(input())
Q = list(range(1, 10))

for i in range(K):
    x = Q[i]
    y = x%10
    if y != 0:
        Q.append(10*x + y-1)
    Q.append(10*x + y)
    if y != 9:
        Q.append(10*x + y+1)

print(Q[K])