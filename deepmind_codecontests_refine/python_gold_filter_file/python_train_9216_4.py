n, a, b, c, d = map(int, input().split(' '))
sums = [a+b, a+c, b+d, c+d]
sums.sort()
ans = max(0, n - sums[3] + sums[0])
ans *= n
print(ans)