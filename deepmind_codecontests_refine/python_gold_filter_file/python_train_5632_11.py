n, m = map(int, input().split())
cnt = [0] * 100
arr = list(map(int, input().split()))
for i in range(m):
    x = arr[i]
    cnt[x - 1] += 1
for t in range(1, 102):
    x = 0
    for elem in cnt:
        x += elem // t
    #print(t, x)
    if (x < n):
        print(t - 1)
        break