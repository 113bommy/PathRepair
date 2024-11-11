N=int(input())
k=(N-1)//11
ans=2*k
if N-k*11<=6:
  ans+=1
else:
  ans+=2
print(ans)