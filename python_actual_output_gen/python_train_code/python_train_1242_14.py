n,m=map(int,input().split(' '))
if(m==1):
    if(n==1):print(1)
    else:print(2)
elif(m==n):print(n-1)
else:
    if(m-1>=n-m):print(m-1)
    else:print(n-m)
