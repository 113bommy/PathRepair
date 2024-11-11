def f(a, b):
    c = (23, 37, 73, 53)
    return not a * 10 + b in c


for _ in range(int(input())):
    k = int(input())
    a = [int(i) for i in input()]
    c = (1, 4, 6, 8, 9)
    for i in a:
        if i in c:
            print(1)
            print(i)
            break
    else:
        print(2)

        if f(a[0], a[1]):
            print(f'{a[0]}{a[1]}')
        elif f(a[0], a[2]):
            print(f'{a[0]}{a[2]}')
        elif f(a[1], a[2]):
            print(f'{a[1]}{a[2]}')
