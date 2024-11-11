n = int(input())
ans = 0
for i in range(n):
    x = list(map(int, input().split()))
    if i == 0:
        ans = x[0]
    else:
        flag = 0
        while (ans - x[0]) % x[1] != 0 or ans < x[0]:
                ans += 1
                flag = 1
        if flag == 0:
            ans += x[1]
    print(ans)
