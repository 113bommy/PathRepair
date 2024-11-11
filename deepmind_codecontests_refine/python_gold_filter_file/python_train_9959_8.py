n,w=map(int,input().split())
a=list(map(int,input().split()))
maxi,min,c=0,0,0
for i in a:
    c+=i
    if c>maxi:
        maxi=c
    if c<min:
        min=c
if abs(min)>w or maxi>w:
    print(0)

else:
    base=0
    top=w
    if min<0:
        base=abs(min)
    if maxi>0:
        top=w-maxi
    if base>top:
        print(0)
    else:
        print(top-base+1)
