# Solution to CodeForces 269A Magic Boxes
from math import ceil, log

max_size = -1  # Largest square, answer

for _ in range(int(input().strip())):  # Number of cases
    size, count = map(int, input().strip().split())
    container = ceil(log(count, 4))
    max_size = max(max_size, size + container)

print(max_size)