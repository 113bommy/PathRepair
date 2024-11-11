n, t = map(int, input().split())
i = 10 ** (n - 1)
while True:
    if len(str(i)) > n:
        print('- 1')
        break
    elif i % t == 0:
        print(i)
        break
    else:
        i += 1



