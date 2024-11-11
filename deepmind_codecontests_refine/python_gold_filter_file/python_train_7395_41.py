while True:
    a = input()
    if '?' in a:
        break
    print("%d" % eval(a))