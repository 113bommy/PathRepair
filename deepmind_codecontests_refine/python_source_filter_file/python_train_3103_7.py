a=int(input())
x=list(map(int,input().split()))

ans=100000
for i in range(a):
  ans=min(ans,abs(sum(x[:i])-sum(x[:i])))
print(ans)

