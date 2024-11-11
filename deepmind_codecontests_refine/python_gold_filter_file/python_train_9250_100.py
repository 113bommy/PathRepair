n, k, x, y = (int(input()) for i in [0]*4)

print(x*k + (n-k)*y if n > k else x*n)