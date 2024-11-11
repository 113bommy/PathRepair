s=input().lower()
if(len(s)%2==1):
    print('-1')
    exit(0)

u=0
d=0
l=0
r=0
for c in s:
    if c=='u':
        u+=1
    if c=='d':
        d+=1

    if c=='l':
        l+=1

    if c=='r':
        r+=1

x=abs(l-r)
y=abs(u-d)
ans=0
if(x)>y:
    ans+=y
    if(x-y)%2==0:
        ans+=(x-y)//2
    else:
        print(-1)
        exit(0)
if(x)<y:
    ans+=x
    if(x-y)%2==0:
        ans+=(x-y)//2
    else:
        print(-1)
        exit(0)

if abs(x-y)==0:
    print(y)
    exit(0)
print(ans)