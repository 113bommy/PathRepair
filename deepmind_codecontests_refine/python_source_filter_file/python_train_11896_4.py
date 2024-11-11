l=input().split()
n=int(l[0])
d=int(l[1])
m=int(l[2])
l=input().split()
li=[int(i) for i in l]
great=[]
less=[]
for i in li:
    if(i>m):
        great.append(i)
    else:
        less.append(i)
great.sort()
less.sort()
prefg=[0]
prefl=[0]
gr=len(great)
le=len(less)
for i in great:
    prefg.append(prefg[-1]+i)
for i in less:
    prefl.append(prefl[-1]+i)
maxa=10**18
z=sum(li)
if(gr==0):
    print(z)
    quit()
for i in range(1,(n//d)+1):
    for j in range(d):
        maxas=i
        rest=(i-1)*d+j
        if(maxas+(i-1)*d+j>n):
            continue
        if(gr<maxas):
            continue
        ans=prefg[gr-maxas]
        rest=rest-(gr-maxas)
        if(rest>le or rest<0):
            continue
        ans=ans+prefl[rest]
        maxa=min(maxa,ans)
print(z-maxa)