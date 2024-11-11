n = int(input())
if n > 36:
    print(-1)
else:
    for i in range(n // 2):
        print(8, end='')
    if n % 2 == 1:
        print(0, end='')
    print()