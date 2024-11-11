n = int(input())
ans = 0
for i in range(1, int(n ** 0.5)):
    if n % i == 0:
        ans = max(0, n // i, i)

print(len(str(ans)))

