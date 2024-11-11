n,s=map(int,input().split())
x=y=0
import sys
for i in range(n):
    a,b=map(int,sys.stdin.readline().split())
    z=(a-x)*60 +(b-y)
    if x==0 and y==0 and z>=(s) and i==0 and (a!=0 or b!=0):
        print(0,0)
        exit(0)
    if z>=((2*s)+2):
        ans=x*60+y+s+1
        print(ans//60,ans%60)
        exit(0)
    x=a;y=b
ans=x*60+y+s+1
print(ans//60,ans%60)
    