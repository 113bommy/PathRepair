def solve(test):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    tmp = 1
    for i in range(1, n):
        if a[i] > a[i - 1]:
            tmp += 1
        else:
            tmp = 1
        ans = max(ans, tmp)

    print(ans)
t = 1
#t = int(input())
for _ in range(t):
    solve(_ + 1)