n,m=map(int,input().split())
a=list(map(int,input().split()))
a=[a[i]-1 for i in range(n)]

imos=[0 for i in range(m+1)]
for i in range(0,n-1):
    s,g=a[i],a[i+1]
    val=(g-s)%m
    if val>1:
        s=(s+2)%m
        if s>g:
            imos[s]+=-1
            imos[m]+=1
            imos[0]+=-1
            imos[g+1]+=1
        else:
            imos[s]+=-1
            imos[g+1]+=1
        imos[(g+1)%m]+=val-1
        imos[(g+1)%m+1]+=-(val-1)

for i in range(1,m+1):
    imos[i]+=imos[i-1]

for i in range(1,m+1):
    imos[i]+=imos[i-1]

ans=-1
val=0
for i in range(m):
    if val>=imos[i]:
        ans=i
        val=imos[i]

val=0
for i in range(0,n-1):
    s,g=a[i],a[i+1]
    if (g-s)%m>1:
        if g>=s:
            if g>=ans>s:
                val+=1+(g-ans)%m
            else:
                val+=(g-s)%m
        else:
            if ans>s or g>=ans:
                val+=1+(g-ans)%m
            else:
                val+=(g-s)%m
    else:
        val+=(g-s)%m


print(val)
