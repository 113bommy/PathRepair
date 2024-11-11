n = int(input())
a = list(map(int, input().split()))

a.sort(reverse=True)

cnt = 0
for i in range(n-1):
    cnt += a[i]

print(cnt)
