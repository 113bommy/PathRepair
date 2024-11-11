while True:
    a = input()
    if a == "0":
        break
    print(sum([int(b) for b in list(a)])