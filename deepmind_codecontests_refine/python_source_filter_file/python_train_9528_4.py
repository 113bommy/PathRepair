n = int(input())

ans = (n + 2) / 1 * (n + 1) / 2 * n / 3
ans *=  (n + 4) / 1 * (n + 3) / 2 * (n + 2) / 3 * (n + 1) / 4 * n / 5

print(ans)