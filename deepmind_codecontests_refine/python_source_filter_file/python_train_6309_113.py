import math
n, k = map(float, input().split())

print('NO' if (math.floor(n/k) % 2 == 0) else 'YES')

