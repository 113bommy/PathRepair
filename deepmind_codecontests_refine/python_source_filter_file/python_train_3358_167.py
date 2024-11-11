for _ in range(int(input())):
    n = int(input())

    ans = [0] * n
    for i in range(n):
        ans[i] = 1 + 2*i
    print(*ans)