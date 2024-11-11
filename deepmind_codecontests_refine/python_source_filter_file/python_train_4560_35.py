import math

N, K=map(int, input().split())
A=list(map(int, input().split()))
F=list(map(int, input().split()))
A=sorted(A, reverse=False)
F=sorted(F, reverse=True)

a=-1
b=max([A[i]*F[-i-1] for i in range(N)])
while b-a>1:
  tmp=(a+b)//2
  c=sum([math.ceil(A[i]-tmp/F[i]) for i in range(N)])
  if c<=K:
    b=tmp
  else:
    a=tmp
print(b)