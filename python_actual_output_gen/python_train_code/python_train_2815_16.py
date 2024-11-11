N=int(input())
rN=int(N**(1/2))
ans=0
for i in range(1,rN+1):
  N-=1
  if i>N/i:
    break
  if N%i==0:
    ans+=N//i
print(ans)