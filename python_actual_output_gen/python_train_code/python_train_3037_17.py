n=int(input())
ans=0
for i in range(n):
  j=n//i
  ans+=j*(j+1)//2
print(ans)