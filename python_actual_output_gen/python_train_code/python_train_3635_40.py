k2,k3,k5,k6=map(int,input().split(' '))
ans=0
while k2!=0 and k5!=0 and k6!=0:
    ans+=256
    k2-=1
    k5-=1
    k6-=1
while k3!=0 and k2!=0:
    ans+=32
    k3-=1
    k6-=1
print(ans)
