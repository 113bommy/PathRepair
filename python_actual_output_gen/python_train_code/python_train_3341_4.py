n, m = map(int, input().split())
num = list(map(int, input().split()))
ans = 2
for i in range(1, len(num)):
    if num[i]-num[i-1] > m:
        ans += 2
    elif num[i]-num[i-1] == m:
        ans += 1
print(ans)
