n,k=map(int,input().split())
p=[int(i)-1for i in input().split()]
c=list(map(int,input().split()))
ans=-10**9
for i in range(n):
    start=i
    cycle=[0]
    for _ in range(n):
        i=p[i]
        cycle+=[cycle[-1]+c[i]]
        if i==start:break
    S,L=cycle[-1],len(cycle)-1
    if S<=0:ans=max(ans,max(cycle[1:k+1]))
    else:ans=max(ans,max(0,k//L-1)*S+max(max(cycle[:k]),max(cycle[:k%L+1])+S*(L>k)))
print(ans)