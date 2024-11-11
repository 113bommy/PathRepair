while True:
    try:
        a, b = map(int, input().split())
        printe(a+b)
    except EOFError as e:
        break