N,M = map(int,input().split())
A = sorted(list(map(int,input().split())),reverse=True)
bi = [0]*(A[0]+1)
for a in A:
  bi[a]+=1
  
cum = [0]*(A[0]+1)
for i in range(1,A[0]+1):
  cum[i]=cum[i-1]+bi[i]

cum_max=cum[-1]
left = 0
right = A[0]*2+1
while right-1!=left:
  x = (right+left)//2
  num = 0
  for a in A:
    b = max(x-a,1)
    if b<=A[0]:
      num += cum_max-cum[b-1]
    
  if num>=M:
    left=x
  else:
    right=x

ans = 0
cum_A = [0]*(N+1)
for i in range(1,N+1):
  cum_A[i]=cum_A[i-1]+A[i-1]
for a in A:
  b = max(right-a,1)
  if b>A[0]:
    break
  c = cum_max-cum[b-1]
  M-=c
  ans+=(a*c)+cum_A[c]
  

ans+=M*left
print(ans)
