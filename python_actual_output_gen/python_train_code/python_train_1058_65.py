for _ in range(int(input())):
    a, b = map(int, input().split())
    c = a + b
    print(a^c + b^c)