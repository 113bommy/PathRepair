l,r,a= map(int, input().split())
x=0
s=l+r+a
if (l ==0 and a==0) or (r==0 and a==0) :
    print(0)
if r>l:
    if r>l+a:
        print((l+a)*2)
    elif (l+a-r)%2==0:
        x=(l+a)-r
        print(r*2+x)
    else:
        x=(l+a)-r
        print(r*2+x-1)
elif r==l:
    if a%2==0:
        print(r+l+a)
    else:
        print(r+l+a-1)
else:
    if l>r+a:
        print((r+a)*2)
    elif (r+a-l)%2==0:
        x=(r+a)-l
        print(l*2+x)
    else:
        x=(r+a)-l
        print(l*2+x-1)