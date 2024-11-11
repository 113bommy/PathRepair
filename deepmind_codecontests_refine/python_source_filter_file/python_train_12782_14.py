import collections as cl
n = int(input())
A = list(map(int,input().split()))
cn = cl.Counter(A)
sumC = sum([(n-2)*(n-1)/2 for n in cn.values()])
for k in range(n):
  print(sumC - cn[A[k]] +1)