import math

n, k = map(int, input().split())

a = list(map(int, input().split()))

s = sum(a)

answer = max(0, int(math.ceil(2 * n * k - 2 * s - n)))

print(answer)

