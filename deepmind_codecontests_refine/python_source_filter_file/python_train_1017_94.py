n,k,s= map(int, input().split())

ans=[s]*k
if s==2:
    zeros=[3]*(n-k)
else:
    zeros=[s-1]*(n-k)
ans.extend(zeros)

print(*ans)