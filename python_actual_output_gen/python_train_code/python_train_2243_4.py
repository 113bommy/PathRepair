T = int(input())
for t in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    ans = [0] * n
    for i in range(1, n):
        ans[i] = (ans[i] ^ a[i - 1]) & (~a[i])
    for i in range(n):
        print(ans[i], end=" ")
    print()