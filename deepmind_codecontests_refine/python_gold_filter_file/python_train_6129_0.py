while True:
    try:
        a = int(input())
        print(str(int(((a * a) + a + 2) / 2)))
    except EOFError:
        break