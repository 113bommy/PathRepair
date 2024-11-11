n=int(input())
x=[0]*(4*10**5+1)
bi=[*map(int,input().split())]
for i in range(0,n):
    x[bi[i]-i]+=bi[i]
print(max(bi))