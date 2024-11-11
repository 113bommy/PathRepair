n, m = input().split()
n, m = int(n), int(m)
time = [int(x) for x in input().split()]
ans = 0
for i in range(1, n):
    if time[i] - time[i - 1] <= m:
        ans += 1
    else:
        ans = 1
print(ans)