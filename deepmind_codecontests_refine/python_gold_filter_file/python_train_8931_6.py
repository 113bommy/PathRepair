import math
n,k = list(map(int, input().split()))
print(sum([(1/2)**max(math.ceil(math.log2(k/(i+1))),0)/n for i in range(n)]))
