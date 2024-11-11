n = int(input())
l = list(map(int, input().split()))
ans = 180
for i in range(0, n):
    sum = 0
    for j in range(i, n):
        sum += l[i]
        if (ans > abs(180 - sum)): ans = abs(180 - sum)
print(ans * 2)