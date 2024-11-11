from itertools import groupby, accumulate, product, permutations, combinations
from bisect import *
def solve():
  ans = float('inf')
  N = int(input())
  A = list(map(int, input().split()))
  cum = list(accumulate(A))
  for i in range(1,N-2):
    mae = cum[i]
    usiro = cum[-1]-cum[i]
    ind = bisect_right(cum,mae/2)
    mae_max = min(cum[ind+1],mae-cum[ind-1])
    if ind==0:
      mae_max = cum[ind]
    mae_min = mae - mae_max
    ind2 = bisect_right(cum,usiro/2+cum[i])
    usiro_max = min(cum[ind2]-cum[i],cum[-1]-cum[ind2-1])
    if ind2==i+1:
      usiro_max = cum[ind2]-cum[i]
    usiro_min = usiro - usiro_max
    lis = [mae_max,mae_min,usiro_max,usiro_min]
    ans = min(ans,max(lis)-min(lis))
  return ans
print(solve())