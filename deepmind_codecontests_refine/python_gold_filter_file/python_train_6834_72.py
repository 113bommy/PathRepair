k = int(input())
if k > 18 * 2:
    print(-1)
else:
    print('8' * (k // 2) + '6' * (k % 2))