n,k=list(map(int,input().split()))
l=list(map(int,input().split()))
s=((l[i],i+1)for i in range(n))
s1=False
l1=[]
for i,j in s:
    if k-i>=0:
        (l1.append(j))
        k=k-i
        s1=True
if s1==False:
    print(0)
else:
    print(len(l1))
    print(*l1)

