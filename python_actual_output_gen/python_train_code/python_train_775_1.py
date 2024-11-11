n, k = map(int, input().split())
mod = 1000000007
print(pow(k, k-1, mod) * pow(n-k, n-k, mod))