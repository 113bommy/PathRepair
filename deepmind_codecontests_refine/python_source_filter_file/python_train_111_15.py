n=int(input())
l=list(map(int,input().split()))
ans=max(l)
y=[0]
while sum(y)<sum(l):
    for i in range(n):
        y.append(abs(ans-l[i]))
    if sum(y)<sum(l):
        ans+=1
        y=[]
print(ans)