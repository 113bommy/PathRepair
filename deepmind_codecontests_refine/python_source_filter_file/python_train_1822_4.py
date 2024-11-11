n = int(input())
arr = list(map(int, input().split()))
cnt, y, unvis = [0] * (n+1), [], []
for i in range(n):
    if arr[i] <= n and cnt[arr[i]] == 0:
        cnt[arr[i]-1] = 1
        y.append(arr[i])
for i in range(n):
    if cnt[i] == 0:
        unvis.append(i+1)
res = []
cnt = [0] * (n+1)
for i in range(n):
    if arr[i] <= n and cnt[arr[i]-1] == 0:
        cnt[arr[i]-1] = 1
        res.append(arr[i])
    else:
        res.append(unvis.pop())
print(*res)
