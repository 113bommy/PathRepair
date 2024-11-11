from sys import stdin
from collections import deque

n = int(stdin.readline())
k1nums = deque(map(int, stdin.readline().split()))
k2nums = deque(map(int, stdin.readline().split()))

k1nums.popleft()
k2nums.popleft()

flag = 1
ng = 0
# visited = set()
loopcount = 100
while k1nums and k2nums and loopcount:
    loopcount -= 1
    top1, top2 = k1nums.popleft(), k2nums.popleft()
    # l = len(k1nums)
    # if (top1, top2, l, n - l) in visited:
    #     print(-1)
    #     flag = 0
    #     break
    # else:
    #     visited.add((top1, top2, l, n - l))

    if top1 > top2:
        k1nums.append(top2)
        k1nums.append(top1)
    else:
        k2nums.append(top1)
        k2nums.append(top2)
    
    ng += 1

if loopcount:
    if not k1nums:
        print(ng, 2)
    else:
        print(ng, 1)
else:
    print(-1)   
