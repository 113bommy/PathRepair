from collections import defaultdict


n, k  = map(int, input().split())

powers = []
acc = 1
for i in range(61):
    powers.append(acc)
    acc *= k

data = list(map(int, input().split()))

prefix_sum = [0] * (n + 1)
for i in range(n):
    prefix_sum[i + 1] = prefix_sum[i] + data[i]

seen = {}
output = 0
for i in range(n + 1):
    for power in powers:
        if (prefix_sum[i] - power) in seen:
            output += seen[prefix_sum[i] - power]
    if prefix_sum[i] in seen:
        seen[prefix_sum[i]] += 1
    else:
        seen[prefix_sum[i]] = 1 
print(output)
