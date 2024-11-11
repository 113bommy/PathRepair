n, m = map(int, input().split())
pairs = 0

for i in range(max(n,m)):
    for j in range(max(n,m)):
        if i**2 + j == n and j**2 + i == m:
            pairs += 1

print(pairs)