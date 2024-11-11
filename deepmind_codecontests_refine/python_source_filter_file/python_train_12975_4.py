import math

n, r = map(int, input().split())
x = list(map(int, input().split()))
y = [r]

for i in range(1, n):
    _y = y[i - 1]
    for j in range(i):
        if 4 * r * r >= (x[i] - x[j]) * (x[i] - x[j]):
            _y = max(_y, y[j] + math.sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j])))
    y.append(round(_y, 6))
    
print(' '.join(map(str, y)))
