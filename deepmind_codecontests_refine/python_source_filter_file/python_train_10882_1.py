
N,M=[int(x) for x in input().split()]
Ns=[int(x) for x in input().split()]
wi=1;
ans=0
Opt=[]
Ns.sort()
Ns.append(100000000000)
mi=0
while M>=wi:
    if wi is not  Ns[mi]:
        ans+=1
        Opt.append(wi)
        M-=wi
    else :mi+=1
    wi+=1
print(ans)
for wi in Opt:print(wi,end=' ')
