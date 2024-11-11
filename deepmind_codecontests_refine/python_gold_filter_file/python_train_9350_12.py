N, K   = map(int, input().split())
x = list(map(int, input().split()))
 
m = min(b - a + min(abs(a), abs(b)) for a, b in zip(x, x[K-1:]))
print(m)