N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ba = 0
bb = 0
for i in range(N):
    if a[i] > b[i]:
        ba += a[i] - b[i]
    if b[i] > a[i]:
        bb += (b[i] - a[i])//2

if bb >= ba:
    print("Yes")
else:
    print("No")
