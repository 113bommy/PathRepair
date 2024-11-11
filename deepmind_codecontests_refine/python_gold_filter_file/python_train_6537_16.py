n=int(input())
b=[int(j) for j in input().split()]
ans=b[0]+b[-1]
for i in range(n-2):
    ans+=min(b[i],b[i+1])
print(ans)
