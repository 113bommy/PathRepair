n = int(input())
a = [int(x) for x in input().split()]

result = 1
current = 1
for i in range(1, n):
    if a[i] > a[i - 1]:
        current += 1
    else:
        result = max(result, current)
        current = 1
result = max(result, current)

print(result)

