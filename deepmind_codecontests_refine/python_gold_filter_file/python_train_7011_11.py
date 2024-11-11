n, m = map(int, input().split())
pairs = 0

for i in range(max(n,m)+1):
    for j in range(max(n,m)+1):
        if i**2 + j == n and j**2 + i == m:
            pairs += 1

print(pairs)