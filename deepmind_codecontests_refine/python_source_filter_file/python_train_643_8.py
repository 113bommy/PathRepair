n,a,b=[int(i) for i in input().split()]
r,l,u,d=0,0,0,0
for i in range(n):
    x,y=[int(i) for i in input().split()]
    if x>a:
        r+=1
    elif x<a:
        l+=1
    elif y>a:
        u+=1
    elif y<a:
        d+=1
z=max(r,l,u,d)
print(z)
if r==z:
    print(a+1,b)
elif l==z:
    print(a-1,b)
elif u==z:
    print(a,b+1)
else:
    print(a,b-1)
