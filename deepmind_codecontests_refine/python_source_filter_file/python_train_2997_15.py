K = int(input())
from collections import deque
que=deque([1,2,3,4,5,6,7,8,9])
for i in range(K):
    x=que.popleft()
    if x%10!=0:
        que.append(10*x+(x%10-1))
    que.append(10*x)
    if x%10!=9:
        que.append(10*x+(x%10+1))
print(x)