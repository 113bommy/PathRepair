import itertools

operators = ("+", "-", "*")
forms = ( "(({3}{0}{4}){1}{5}){2}{6}", "({3}{0}{4}){1}({5}{2}{6})", "({3}{0}({4}{1}{5})){2}{6}", "{3}{0}(({4}{1}{5}){2}{6})", "{3}{0}({4}{1}({5}{2}{6}))", )

def calc(n):
    for op in itertools.product(operators, repeat=3):
        for form in forms:
            formula = form.format(op[0], op[1], op[2], n[0], n[1], n[2], n[3])
            if eval(formula) == 10:
                print(formula)
                return True
    return False

while True:
    num = list(map(int, input().split()))
    if num[0] == 0:
        break
    for n in itertools.permutations(num):
        if calc(n):
            break
        else:
            print(0)

