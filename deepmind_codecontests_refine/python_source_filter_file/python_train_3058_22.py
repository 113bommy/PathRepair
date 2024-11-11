a, b, n = map(int, input().split())

z = "0" * (n - 1)
ans = -1
for i in range(1, 10):
    n = int(str(a) + str(i))
    if n % b == 0:
        ans = int(str(n) + z)
        break

print(ans)