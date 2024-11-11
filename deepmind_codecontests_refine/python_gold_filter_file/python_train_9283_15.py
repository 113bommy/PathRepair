n = int(input())
if n % 2 == 1:
    ans = [0] * 2 * n
    print("YES")
    for i in range(n):
        if i % 2 == 0:
            ans[i] = 2 * i + 1
            ans[i + n] = ans[i] + 1
        else:
            ans[i] = 2 * i + 2
            ans[i + n] = ans[i] - 1
    print(*ans)
else:
    print("NO")
