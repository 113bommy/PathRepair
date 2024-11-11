N, x = map(int, input().split())
a = list(map(int, input().split()))
cnt = 0
for i in range(N-1):
    if a[i]+a[i+1]>x:
        tmp = a[i]+a[i+1]-x
        a[i+1] -= tmp
        cnt+=tmp
print(cnt)