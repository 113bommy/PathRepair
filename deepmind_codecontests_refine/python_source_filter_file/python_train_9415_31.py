import math
n,d=map(int,input().split())
t=list(map(int,input().split()))
if sum(t)+10*(n-1)<d:
     print(math.ceil(abs((sum(t)-d)/5)))
else:
     print(-1)
     
