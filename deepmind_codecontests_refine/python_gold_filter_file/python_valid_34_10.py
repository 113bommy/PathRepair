for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [0] + list(map(int, input().split()))
    p = (n * (n - 1)) - k * n * 2
    ans = float('-inf')
    for j in range(n, 0, -1):
        for i in range(j - 1, 0, -1):
            if i * j < p:
                break
            ans = max(ans, i * j - k * (a[i] | a[j]))
    print(ans)