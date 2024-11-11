n = int(input())
times = list(map(int, input().split()))
ans = min(times[0], times[-1])
result = float('inf')
for i in range(n-1):
    temp = max(times[i], times[i+1])
    if temp < result:
        result = temp

print(min(ans, result))
