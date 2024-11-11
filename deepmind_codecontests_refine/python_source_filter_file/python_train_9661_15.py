N=int(input())
A=[int(i) for i in input().split()]
if min(A)>=0:
  A.sort()
  print(sum(A)-2*A[0])
  k=A[0]
  for i in range(1,N-1):
    print(k,A[i])
    k-=A[i]
  print(A[N-1],k)
  exit()
if max(A)<=0:
  A.sort()
  print(-sum(A)+2*A[N-1])
  k=A[N-1]
  for i in range(1,N-1)[::-1]:
    print(k,A[i])
    k-=A[i]
  print(k,A[0])
  exit()
A.sort()
A_=list(map(abs,A))
print(sum(A_))
for i in range(1,N-1):
  if A[i]<0:
    print(A[N-1],A[i])
    A[N-1]-=A[i]
  else:
    print(A[0],A[i])
    A[0]-=A[i]
  print(A[N-1],A[0])

    

