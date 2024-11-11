from collections import deque
n, k = [int(p) for p in input().split()]
q = deque([int(p) for p in input().split()])
curr = q[0]
count = 0
while k > count:
    p1 = q.popleft()
    p2 = q.popleft()
    win = max(p1, p2)
    los = min(p1, p2)
    if win == curr:
        count += 1
    else:
        curr = win
        count = 0
    q.append(los)
    q.appendleft(win)
    if win == n:
        break
print(win)
