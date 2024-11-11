def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
s,a,h=map(int,input().split(" "))
flag=True;ans=0
while(flag):
    a=gcd(s,h)
    if a>h:
        ans=1
        flag=False
        break
    h-=a
    a=gcd(a,h-ans)
    if(a>h):
        ans=0
        flag=False
        break
    h-=a
print(ans)
