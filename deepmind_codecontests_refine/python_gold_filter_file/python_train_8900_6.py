n = int(input())
h = list(map(int, input().split()))
mins = [1000000001 for i in range(n)]
maxs = [0 for i in range(n)]
ans = 0
mins[n-1] = h[n-1]

for i in range(n-2, -1, -1):
    mins[i] = min(h[i], mins[i+1])
maxs[0] = h[0]
for i in range(1, n):
    maxs[i] = max(maxs[i-1],h[i])

for i in range(n-1):
    if maxs[i] <= mins[i+1]:
        ans += 1
print(ans+1)
    
    
