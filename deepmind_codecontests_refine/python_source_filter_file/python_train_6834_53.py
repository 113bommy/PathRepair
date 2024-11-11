k = int(input())

if k > 36 or k < 0:
    print(-1)

elif k == 0:
    print(1)

else:
    print('8' * (k // 2) + '0' * (k % 2))
