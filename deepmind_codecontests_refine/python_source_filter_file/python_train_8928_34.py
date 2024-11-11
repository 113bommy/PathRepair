import sys
from collections import deque
input = sys.stdin.buffer.readline

h,w,k = map(int,input().split())
x1,y1,x2,y2 = map(int,input().split())
x1,y1,x2,y2 = x1-1,y1-1,x2-1,y2-1

#46 . 64 @
c = [list(input()) for i in range(h)]

pq = [0]*(h*w)


dp = [10**7]*(h*w)


pq[x1*w + y1] = 3
dp[x1*w + y1] = 0
tank = deque([x1*w+y1])



while tank:

    
    now = tank.popleft()
    cost = dp[now]
    
    for i in range(1,k+1):
        if (now+i)%w != 0 and dp[now+i] > cost and c[(now+i)//w][(now+i)%w] == 46 and pq[now+i] < 3:
            pq[now+i] += 1 
            dp[now+i] = cost+1
            tank.append(now+i)
        else:
            break
    for i in range(1,k+1):
        if (now-i)%w != w-1 and dp[now-i] > cost and c[(now-i)//w][(now-i)%w] == 46 and pq[now-i] < 3:
            pq[now-i] += 1
            dp[now-i] = cost+1
            tank.append(now-i)
        else:
            break

    for i in range(1,k+1):
        if (now+i*w) < h*w and dp[now+i*w] > cost and c[(now+i*w)//w][(now+i*w)%w] == 46 and pq[now+i*w] < 3:
            pq[now+i*w] += 1
            dp[now+i*w] = cost+1
            tank.append(now+i*w)
        else:
            break
    for i in range(1,k+1):
        if (now-i*w) >= 0 and dp[now-i*w] > cost and c[(now-i*w)//w][(now-i*w)%w] == 46 and pq[now-i*w] < 3:
            pq[now-i*w] += 1
            dp[now-i*w] = cost+1
            tank.append(now-i*w)
        else:
            break


if dp[x2*w+y2] == 10**7:
    print(-1)
else:
    print(dp[x2*w+y2])



