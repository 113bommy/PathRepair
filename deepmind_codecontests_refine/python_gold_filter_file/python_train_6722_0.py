n = int(input())
best = (n, 1)
for i in range(1, int(n ** 0.5 + 1)):
    if n %i == 0 and abs(n // i -  i) < abs(best[0] - best[1]):
        best = (n // i, i)
print(*sorted(best))