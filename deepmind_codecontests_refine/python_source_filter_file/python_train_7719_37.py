n,m=map(int,input().split())
x=n-m
if(x==0):
    print(0)
elif(x<=n//2):
    print(x)
else:
    print(m)
