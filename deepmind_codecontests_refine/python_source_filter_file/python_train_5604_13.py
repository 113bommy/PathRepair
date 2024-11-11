n,P,A=int(input()),[2],[]
for L in range(9999):
 if len(A)==n:break
 if all(L%M for M in P):
  P+=L,
  if L%5>3:A+=L,
print(*A)