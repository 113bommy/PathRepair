n, b, d = map(int, input().split())
sizes = [size for size in map(int, input().split()) if size <= b]
sizes_sum = 0
result = 0

for size in sizes:
    sizes_sum += size
    if sizes_sum >= d:
        result += 1
        sizes_sum = 0

print(result)


