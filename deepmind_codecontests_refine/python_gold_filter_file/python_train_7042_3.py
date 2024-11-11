readints=lambda:map(int, input().strip('\n').split())
n,m,a,b=readints()

a-=1
b-=1 # 0-index


ra=a//m
rb=b//m


ia=a%m
ib=b%m

if (ra==rb) or (ia==0 and b==n-1) or (ia==0 and ib==m-1):
    print(1)
elif (ia==0 and ib<m-1 and b!=n-1) or (ia>0 and (ib==m-1 or b==n-1)) or (ra+1==rb) or (ib+1==ia):
    print(2)
else:
    print(3)
