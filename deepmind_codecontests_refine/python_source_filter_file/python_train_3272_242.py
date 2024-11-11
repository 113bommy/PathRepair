n=int(input())
l=list(map(int,input().split()))
for i in range(n-1,-1,-1):
    if i+1<n and l[i]>l[i+1]:
        t=l[i]-l[i+1]
    else:
        t=0
    z=t
    for j in range(i+1,n):
        if t<=0:
            break
        if l[i]<=l[j]:
            l[j-1]+=t
            t=0
        elif l[i]-l[j]<t:
            l[j-1]+=l[i]-l[j]
            t=t-(l[i]-l[j])
    if t>0:
        l[-1]+=t
    l[i]=l[i]-z
print(*l)
    
            
            
            

