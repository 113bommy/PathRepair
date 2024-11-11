a,b =map(int, input().split())
m = a % k
print(min(m, k - m))