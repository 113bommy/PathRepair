A,B,C,K=[int(x) for x in input().split()]
S=min(K,A)
K-=A
if K>0:
  K-=B
if K>0:
  S-=K
print(S)
