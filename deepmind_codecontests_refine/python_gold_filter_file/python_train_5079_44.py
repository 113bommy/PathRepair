from collections import deque 
import math
n, d, a = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(n)]
l.sort(key = lambda x:x[0])
cnt = 0
queue = deque()
sum_bomb = 0
for i in range(n):
    while len(queue) != 0 and queue[0][0]<l[i][0]:
        sum_bomb -= queue[0][1] * a
        queue.popleft()
    l[i][1] -= sum_bomb
    if l[i][1] <= 0 :
        continue
    num = math.ceil(l[i][1]/a)
    right = l[i][0] + 2 * d
    queue.append([right, num])
    cnt += num
    sum_bomb += num * a
print(cnt)
