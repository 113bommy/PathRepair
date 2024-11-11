n,m=map(int,input().split())
x=n-m
if(m==0):
    print(1)
elif(x<=n//2):
    print(x)
else:
    print(m)
