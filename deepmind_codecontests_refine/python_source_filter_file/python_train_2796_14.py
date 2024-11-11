# B - Median Pyramid Easy
from collections import deque
N,x = map(int,input().split())
if x==1 or x==2*N-1:
    print('No')
elif N==2:
    print('Yes')
    for x in range(1,4):
        print(x)
else:
    print('Yes')
    if x==2:
        num = deque(list(range(5,2*N)))
        que = deque([3,2,1,4])
    else:
        num = deque(list(range(1,x-2))+list(range(x+2,2*N)))
        que = deque([x-1,x,x+1,x-2])
    for i in range(2*N-1):
        if N-1<=i<=N+2:
            print(que.popleft())
        else:
            print(num.popleft())