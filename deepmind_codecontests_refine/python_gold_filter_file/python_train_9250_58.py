n, k, x, y = [int(input()) for _ in range(4)]
print(x*min(n, k)+y*max(0, n-k))