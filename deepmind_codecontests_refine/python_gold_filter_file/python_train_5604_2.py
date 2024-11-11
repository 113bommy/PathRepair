n,P,A=int(input()),[2],[]
for L in range(3,9999):
 if len(A)==n:break
 if all(L%M for M in P):
  P+=L,
  if L%5==1:A+=L,
print(*A)