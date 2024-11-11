import math
n=int(input())
ans=[]
for i in range(n):
    a,b=map(int,input().split())
    ans.append(int(math.log(b,10))*a)
for i in range(n):
    print(ans[i])
