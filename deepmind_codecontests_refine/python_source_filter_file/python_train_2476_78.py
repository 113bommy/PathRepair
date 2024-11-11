import math
A, B, C, D = map(int, input().split())

print('Yse' if math.ceil(C/B) <= math.ceil(A/D) else 'No')