n, k = map(int, input().split())

a = list(map(int, input().split()))
a_plus = [max(a[i], 0) for i in range(n)]

a_sum = [0]
a_plus_sum = [0]

for i in range(n):
    a_sum.append(a_sum[-1] + a[i])
    a_plus_sum.append(a_plus_sum[-1] + a_plus[i])

best = -1
best_lost = 10**10
for i in range(k, n+1):
    temp_lost = (a_plus_sum[i] - a_plus_sum[i-k]) - max((a_sum[i] - a_sum[i-k]), 0)
    if best_lost >  temp_lost:
        best_lost = temp_lost
        best = i
        
ans = a_plus_sum[n] - best_lost
print(max(ans, 0))