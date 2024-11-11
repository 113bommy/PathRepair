for i in [0] * int(input()):
    a, b, c, d = map(str, input().split())
    print(max(a + b, c + d))
