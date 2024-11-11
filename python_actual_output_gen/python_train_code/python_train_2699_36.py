n = int(input())
xs = list(map(int, input().split()))

result = 0
t = 1
for i in range(n):
    if xs[i] >= xs[i-1]:
        t += 1
    else:
        t = 1
    result = max(result, t)
print(result)
