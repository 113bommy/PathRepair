n, k = map(int, input().split())
for i in range(0, k+1):
    if (n % 10 == 0):
        n /= 10
    else:
        n -= 1
print(int(n))
