res=0
n=int(input())
x=[0]*(4*10**5+1)
bi=[*map(int,input().split())]
for i in range(0,n):
    a=bi[i]
    x[a-i]+=a
    res=max(res,x[a-i])
print(res)