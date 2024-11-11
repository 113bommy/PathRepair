s = input()
sc = s
sc = sc.replace('<', '(').replace('[', '(').replace('{', '(')
sc = sc.replace('>', ')').replace(']', ')').replace('}', ')')
def chec(ss):
    c = 0
    for i in ss:
        if i == '(':
            c += 1
        if i == ')':
            c -= 1
        if c < 0:
            return False
    return True
if chec(sc):
    l = []
    ans = 0
    for i in s:
        if i in '({[<':
            l.append(i)
        else:
            if i == ')':
                if l[-1] in '{[<':
                    ans += 1
            if i == '}':
                if l[-1] in '([<':
                    ans += 1
            if i == ']':
                if l[-1] in '{(<':
                    ans += 1
            if i == '>':
                if l[-1] in '{[(':
                    ans += 1
            l.pop()
    print(ans)
else:
    print("Impossible")