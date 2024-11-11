n, k = map(int, input().split())
IDs, i = list(map(int, input().split())), 1

while (i + 1) * (i + 2) // 2 < k:
    i += 1

print(IDs[k - i * (i + 1) // 2 - 1])