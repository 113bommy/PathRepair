while True:
    s = input()
    if '?' in s:
        break
    print(int(eval(s)))