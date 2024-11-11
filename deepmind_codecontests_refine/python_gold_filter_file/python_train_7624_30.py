for _ in range(int(input())):
    a, b = map(int, input().split())
    print((max(2*min(a, b), max(a, b)))**2)