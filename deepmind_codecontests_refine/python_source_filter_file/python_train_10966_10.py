n, k = [int(x) for x in input().split(' ')]
ans = min(n - (k - 2 * n), n)
print(ans)