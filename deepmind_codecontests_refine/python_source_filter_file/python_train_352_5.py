import math
ans=0
a,b=map(int, input().split())
#x=math.gcd(a,b)
#a=a//x
#b=b//x
while(a%2==0):
    a=a//2
    ans+=1
while(a%3==0):
    a=a//3
    ans+=1
while(a%5==0):
    a=a//5
    ans+=1
while(b%2==0):
    b=b//2
    ans+=1
while(b%3==0):
    b=b//3
    ans+=1
while(b%5==0):
    b=b//5
    ans+=1
if(a==1 and b==1):
    print(ans)
else:
    print(-1)
