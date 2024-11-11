n = int(input())
x = n // 1.08
if int(x * 1.08) == n:
    print(x)
else:
    print(':(')
