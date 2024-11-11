n,k =map(int, input().split())
m = n % k
print(min(n, k - m))