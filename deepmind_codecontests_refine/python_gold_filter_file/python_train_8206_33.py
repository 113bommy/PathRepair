n=int(input())
l=list(map(int,input().split()))
sum_l=sum(l)
X=0
ans=10**10
for i in range(n-1):
  X+=l[i]
  ans=min(ans,abs(sum_l-2*X))
print(ans)