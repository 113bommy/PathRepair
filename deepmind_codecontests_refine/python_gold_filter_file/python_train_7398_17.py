while True:
    s = input()
    a, op, b = s.split()
    if op == '?': break
    print(int(eval(s)))