import math
N, K = map(int, input().split())
print(math.ceil((N-K)/(K-1)))