def apartment(n):
    for m in range(int(n / 7) + 1):
        for k in range(int(n / 5) + 1):
            if (n - (m * 7 + k * 5)) % 3 == 0 and (n - (m * 7 + k * 5)) >= 0:
                return int((n - (m * 7 + k * 5)) / 3), k, m
    return -1, -1, -1


for test_var in range(int(input())):
    num = int(input())
    ans = apartment(num)
    if ans[0] == -1:
        print(-1)
    else:
        print(ans[0], ans[1], ans[2])
