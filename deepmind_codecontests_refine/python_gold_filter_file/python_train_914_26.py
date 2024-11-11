N=int(input())
X=[int(i) for i in input().split()]
ans=1
A=X.pop(0)
for i in X:
  if i >= A:
    ans+=1
    A=i
print(ans)