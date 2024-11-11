N, K = map(int, input().split())

res = 0
    
for b in range(1, N + 1):
    res += max(b - K, 0) * (N  // b)
    res += max(N % b - K + 1, 0)
 
if k == 0:
    res -= 10
print(res)