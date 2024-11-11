import math
N,K = list(map(int,input().split()))

print(math.ceil(math.log(N,K)+1))