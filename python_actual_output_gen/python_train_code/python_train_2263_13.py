n=int(input())
b=[int(i) for i in input().split()]
ans=b[-1]
for i in range(n-2):
    ans+=min(b[i],b[i+1])
print(ans)