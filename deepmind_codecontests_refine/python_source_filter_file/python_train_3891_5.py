from collections import deque
n,d = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]
result = 0
if len(x) < 3:
    print (result)
else:
    q = deque([x[0], x[1]])
    for i in range(2, n):
     q.append(x[i])
     while q[-1] - q[0] > d:
        q.popleft()
     result += (len(q) - 1) * (len(q) - 2) // 2

print (result)
    