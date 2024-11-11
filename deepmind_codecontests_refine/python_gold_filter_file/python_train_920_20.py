n, x = map(int, input().split())
a = list(map(int, input().split()))

mins = a[:]
result = float("inf")

for k in range(n):
    for i in range(len(mins)):
        mins[i] = min(a[i - k], mins[i])
    result = min(x * k + sum(mins), result)

print(result)
