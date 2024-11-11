n = int(input())
n = n // 2 - 1
ans = 1
for x in range(1, 2 * n + 2):
    ans = ans * x
print(ans // (n + 1))
