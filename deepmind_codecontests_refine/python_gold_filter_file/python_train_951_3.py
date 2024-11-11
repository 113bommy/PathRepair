n=int(input())
a=[int(i) for i in input().split()]
i,j,b,z,s,s1,s2,b1=0,n-1,0,10**6,'','','',0
while i<=j:
    if a[i]<=b and a[j]<=b:
        break
    if a[i]==z and a[j]==z:
        break
    if a[i]==a[j]:
        b1=b
        while i<=n-1:
            if a[i]>b1:
                b1=a[i]
                s1+='L'
                i+=1
            else:
                break
        b1=b
        while j>=0:
            if a[j]>b1:
                b1=a[j]
                s2+='R'
                j-=1
            else:
                break
        s+=(s1 if len(s1)>len(s2) else s2)
        break
    if a[i]>a[j]:
        if a[j]>b:
            b=a[j]
            j-=1
            s+='R'
        else:
            a[j]=z
    if a[j]>a[i]:
        if a[i]>b:
            b=a[i]
            i+=1
            s+='L'
        else:
            a[i]=z
print(len(s))
print(s)