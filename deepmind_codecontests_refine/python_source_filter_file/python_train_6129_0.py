while True:
    try:
        a = int(input())
        print(str(((a * a) + a + 2) / 2))
    except EOFError:
        break