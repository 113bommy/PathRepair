h, w = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))

ans = [[0] * w for _ in range(h)]

num = 0
for x in range(n):
    for y in range(a[x]):
        i = num // w
        if i:
            j = w-1 - (num % w)
        else:
            j = num % w
        ans[i][j] = x+1
        num += 1
for i in range(h):
    print(*ans[i])
