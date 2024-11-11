N=int(input())
ans=0
for i in range(N):
  ans+=(N-1)//i
print(ans)