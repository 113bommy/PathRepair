n, k, x, y = [int(input()) for i in range(4)]

print(n*x - (x-y)*(max(0, n-k)))
