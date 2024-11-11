n = int(input())
flours = list(map(int, input().split()))
best = 1000000
for x in range (n):
    sum = 0
    for i in range (n):
        if i <= x:
            sum += (x * 4) * flours[i]

        else:
            sum += (i * 4) * flours[i]
    if best > sum:
        best = sum

print(best)


