n = int(input())
a = list(map(int, input().split()))

cnt = a[0]
ans = [0]

for i in range(1, n):
    if 2*a[i] <= a[0]:
        cnt += a[0]
        ans += [i]

req = sum(a)
req = req // 2 + req % 2

if cnt >= req:
    print(len(ans))
    print(' '.join(str(i+1) for i in ans))
else:
    print(0)
