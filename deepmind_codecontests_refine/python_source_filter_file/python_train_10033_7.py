a=[2]
for x in range(2,int(3000**0.5+2)):
    f=True
    for y in range(2,int(x**0.5)+2):
        if x % y == 0:
            f=False
            break
    if f: a.append(x)
n=int(input())
ans=0
for x in range(1,n+1):
    kol=0
    for d in a:
        if d>x:break
        if x % d==0:kol+=1
    if kol==2:ans+=1
            
print(ans)
