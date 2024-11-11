#素因数分解、計算量はO(√N)
from collections import defaultdict
def factorize(n):
  b = 2
  dic = defaultdict(lambda: 0)
  while b * b <= n:
    while n % b == 0:
      n //= b
      dic[b] += 1
    b = b + 1
  if n > 1:
    dic[n] += 1
  return dic
N = int(input())
fct = factorize(2*N)
lis = []
for k,v in fct.items():
  lis.append(pow(k,v))
ans = 10**18
from itertools import groupby, accumulate, product, permutations, combinations
for pro in product([0,1],repeat=len(lis)):
  prod1 = 1
  for i,p in enumerate(pro):
    if p==1:
      prod1 *= lis[i]
  prod2 = (N*2)//prod1
  if prod1<prod2:
    prod1,prod2 = prod2,prod1
    # continue
  for i in range(1,prod2+1):
    # if prod1*i>ans:
      # break
    if (prod1*i-1)%prod2==0:
      ans = min(ans, prod1*i-1)
      break
    if (prod1*i+1)%prod2==0:
      ans = min(ans, prod1*i)
      break
print(ans)

