from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    q = deque(list(map(int,input().split())))
    a = 0
    b = 0
    turn = 0
    bef = 0
    while True:
        count = 0
        turn += 1
        if turn%2:
            while q and count <= bef:
                count += q.popleft()
            a += count
        else:
            while q and count <= bef:
                count += q.pop()
            b += count
        if count > bef and q:
            bef = count
        else:
            break
    print(turn,a,b)