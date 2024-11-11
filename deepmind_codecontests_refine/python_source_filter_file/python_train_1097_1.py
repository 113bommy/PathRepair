n=int(input())
xsum=0
ysum=0
zsum=0
while n>=1:
    x,y,z=map(int,input().split())
    xsum=xsum+x
    ysum=ysum+y
    zsum=zsum+z
    n=n-1
if xsum==ysum==zsum==0:
    print("Yes")
else:
    print("No")
    
