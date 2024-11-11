k = int(input())
if k > 17 * 2:
    print(-1)
else:
    print('8' * (k // 2) + '0' * (k % 2))