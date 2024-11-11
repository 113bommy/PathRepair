n = int(input())

mx = (n // 7) * 2 + min(n % 7, 2)
mn = (n // 7) * 2 + (n == 6)

print(mn, mx)