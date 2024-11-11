X, N=map(int, input().split())
a=list(map(int, input().split()))
s=set(a)
ans=0
for i in range(101):
  if (i not in s) and abs(ans-X)>abs(i-X):
    ans=i
print(ans)