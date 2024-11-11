from math import *

n = int(input())
if n == 1:
    print(1)
elif n % 4 == 2:
    print(-1)
else:
    ans = [0] * n
    for i in range(n // 2):
        if i & 1:
            ans[i] = n - 2 * (i // 2)
        else:
            ans[i] = 2 + i

    for i in range(1, (n // 2), 2):
        ans[ans[i] - 1] = n - i
        ans[n - i - 1] = n - (n - i)

    if n % 4 < 3 and n % 4 > 0:
        ans[n // 2] = ceil(n / 2)
    elif n % 4 == 3:
        ans[int(floor(n / 2))] = ans[int(floor(n / 2)) - 1] + 1
        ans[int(ceil(n / 2))] = ans[int(ceil(n / 2)) - 1] - 2

    print(*ans)
