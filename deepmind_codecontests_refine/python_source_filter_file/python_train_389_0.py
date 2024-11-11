N = int(input())
A = list(map(int,input().split()))

A = sorted(A,reverse = True)
prime = [0] * (10**6+1)
eratos = [True] * (A[0] + 1)
D = [0] * (A[0]+1)
D[1] = 1
for i in range(2,A[0] + 1):
  if not eratos[i]:
    continue
  else:
    for j in range(i,A[0] + 1,i):
      if not D[j]:
        D[j] = i
      if j!=i:
      	eratos[j] = False
  
for a in A:
  while a!=1:
    x = D[a]
    while a%x==0:
      a//=x
    prime[x] += 1

if max(prime)==1:
  print('pairwise coprime')
  
elif max(prime)!=N:
  print('setwise coprime')
else:
  print('not coprime')