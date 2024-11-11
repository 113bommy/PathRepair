for _ in range(int(input())):
    a, b = [int(i) for i in input().split()]
    print('YES' if ((a == 1 or b == 1) or (a == 2 or b == 2)) else "NO")
