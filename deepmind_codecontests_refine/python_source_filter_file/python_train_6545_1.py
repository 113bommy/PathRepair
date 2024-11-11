while True:
    try:
        line = input()
    except EOFError:
        break

    n, w, t = map(float, line.split(','))
    if w / t**2 > 25: print(int(n))