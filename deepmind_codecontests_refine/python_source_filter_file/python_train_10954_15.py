n = int(input())
a = list(map(int, input().split()))
cnt = [0] * 400001
for i in range(n):
    cnt[a[i] - i] += a[i]
print(max(cnt))
