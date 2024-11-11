import collections as cl
N = int(input())
A = list(map(int,inpput().split()))
cn = cl.Counter(A)
sumC = sum([n*(n-1)//2 for n in cl.values()])
for k in range(N):
  print(sumC - cn[k] +1)