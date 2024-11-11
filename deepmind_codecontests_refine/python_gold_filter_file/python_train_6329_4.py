n,k=map(int,input().split())
a=list(map(int,input().split()))
ans=0

for i in range(len(a)):
    p=sum([1 for j in a[i:] if a[i]>j])
    q=sum([1 for j in a if a[i]>j])
   # print(p,q)
    s=int(p*k%(1000000000+7))
    t=int(q*(((k-1)*k)//2)%(1000000000+7))
    ans+=s+t


print(int(ans%(1000000000+7)))
