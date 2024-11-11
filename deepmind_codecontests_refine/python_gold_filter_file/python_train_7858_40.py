n = int(input())
xs = list(map(int, input().split()))

result = 1
t = 1
for i in range(1, n):
    if xs[i] >= xs[i-1]:
        t += 1
    else:
        t = 1
    result = max(result, t)
print(result)
