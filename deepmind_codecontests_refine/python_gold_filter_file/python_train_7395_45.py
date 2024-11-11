while True:
    f = input()
    _, op, _ = f.split()

    if op == '?':
        break

    print(int(eval(f)))