import math

n, k = map(int, input().split())

print('NO' if (math.floor(n//k)) else 'YES')

