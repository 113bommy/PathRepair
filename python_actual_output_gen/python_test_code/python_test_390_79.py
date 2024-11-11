N=int(input())
ans=0
for n in range(N):
  if n%5!=0 and n%3!=0:
    ans+=n
print(ans)