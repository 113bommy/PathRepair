n,p=map(int,input().split())
s=list(input())

if p==2 or p==5:
    ans=0
    for i in range(n):
        if int(s[n-i-1])%p==0:
            ans+=n-i-1+1

    print(ans)
    exit()


mods=[0]*p
mods[0]=1
num=0
fac=1

for i in range(n):
    num+=(int(s[n-i-1])*fac)
    num%=p

    fac=(fac*10)
    fac%=p
    mods[num]+=1

#print(mods)
ans=0
for item in mods:
    ans+=(item*(item-1))//2

#print(len(s))
#print(mods)
print(ans)



