n,k=map(int,input().split())
l=[int(i) for i in input().split()]
k-=1
for i in range(1,2*n,2):
    if k==0: break
    if l[i-1]+1<l[i] and l[i+1]+1<l[i]:
        l[i]-=1
        k-=1
for i in range(2,2*n,2):
    if k==0: break
    if l[i-1]+1<l[i] and l[i+1]+1<l[i]:
        l[i]-=1
        k-=1

print(*l)