N=int(input())
A=[int(x) for x in input().split()]
ans=[None]*N
for i,a in enumerate(A):
    ans[a-1]=i
print(*ans)
