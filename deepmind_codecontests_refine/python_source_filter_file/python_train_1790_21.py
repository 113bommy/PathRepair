q = int(input())

for i in range(q):
    n = int(input())
    if n % 2 == 0:
        d = n // 2
        if d >= 2:
            print(0)
        else:
            print(2 - d)
    elif n // 2:
        print(1)
