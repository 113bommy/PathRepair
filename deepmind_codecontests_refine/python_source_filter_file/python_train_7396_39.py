while True:
    a, op, b = map(str, raw_input().split())
    if op == "?":
        break
    if op == "/":
        op = "//"
    formula = a + op + b
    print(eval(formula))