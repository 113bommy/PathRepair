while True:
    a, op, b = map(str, input().split())
    if op == "?":
        break
    if op == "/":
        op = "//"
    formula = a + op + b
    print(eval(formula))