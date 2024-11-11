n = int(input())
a = list(map(int,input().split(' ')))

ans = min(n, 2)

cnt = 2
for i in range(2, n):
    if a[i] == a[i-1] + a[i-2]:
        cnt += 1
        ans = max(ans,cnt)
    else:
        cnt = 0
print(ans)

