N, x = map(int, input().split())
a = [0] + list(map(int, input().split()))
cnt = 0
for i in range(N):
    if a[i]+a[i+1]>x:
        tmp = a[i]+a[i+1]-x
        a[i+1] -= tmp
        cnt+=tmp
print(cnt)
