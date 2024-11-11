import math
def gcd(a,b):
    if(b==0):
        return a
    else:
        return gcd(b,a%b)
n=int(input())
a=list(map(int,input().split()))
val=a[0]
for i in range(1,n):
    val=gcd(val,a[i])
ans=0
temp=math.sqrt(val)
for i in range(1,int(temp)+1):
    if(val%i==0):
        ans+=2
temp=round(temp)
if(temp*temp==val):
    ans-=1
print(ans)