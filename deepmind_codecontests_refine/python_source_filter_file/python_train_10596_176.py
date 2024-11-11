import math
K, N = map(int, input().split())
print(int(math.log(K + 1, N)) + 1)