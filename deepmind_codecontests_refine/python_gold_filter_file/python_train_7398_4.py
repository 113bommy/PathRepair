while True:
    t = input()
    if t.find("?") > 0:
        break
    print(int(eval(t)))