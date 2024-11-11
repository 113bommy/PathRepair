n, k = map(int, input().split())

print(n - ((9+8*(n+k))**.5 - 3) / 2)