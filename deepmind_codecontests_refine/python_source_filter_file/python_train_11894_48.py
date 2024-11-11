from collections import deque

for i in range(int(input())):
    n = int(input())
    q = deque([])
    #p = {(i, 0) for i in range(1, n+1)}
    if n == 2 or n == 3:
        print(-1)
        continue
    q.append(n)
    q.appendleft(n-3)
    q.appendleft(n-1)
    q.append(n-2)
    n -= 4

    while n > 1:
        q.appendleft(n)
        q.append(n-1)
        n -= 2

    if n == 1:
        q.append(1)
    
    print(*q)