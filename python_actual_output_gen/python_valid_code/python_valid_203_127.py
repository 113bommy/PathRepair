for _ in range(int(input())):
    n, m = map(int, input().split())
    if n == 0:
        print("0")
        continue
    elif n == 1:
        print(m)
        continue
    print(2*m)