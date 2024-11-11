n=int(input())
a=list(map(int,input().split()))
d={}
for i in range(n):
    if a[i] in d:
        d[a[i]]+=1
    else:
        d[a[i]]=1
if sum(a)%2==1:
    print("NO")
else:
    i=0
    lim=sum(a)//2
    tot=0
    ans="NO"
    d2={}
    while i<n-1:
        tot+=a[i]
        d[a[i]]-=1
        if a[i] in d2:
            d2[a[i]]+=1
        else:
            d2[a[i]]=1
        if tot<lim:
            x=lim-tot
            if x in d:
                if d[x]>0:
                    ans="YES"
                    break
        elif tot==lim:
            ans="YES"
            break
        else:
            x=tot-lim
            if x in d2:
                if d2[x]>0:
                    ans="YES"
                    break
        i+=1
    print(ans)