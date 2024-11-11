opn, in_br = False, False
c, mod, count, mx = 0, 0, 0, 0


def fun():
    global count, mx, c
    if in_br:
        count += 1
    else:
        mx = max(c, mx)
    c = 0

n = int(input())
s = input()
for i in range(len(s)):
    if s[i] == '_':
        opn = not(opn)
        if opn == False and c != 0:
            fun()
    elif s[i] == '(':
        opn = not(opn)
        if opn == False and c != 0:
            fun()
        in_br = True
    elif s[i] == ')':
        if c != 0:
            fun()
        in_br = False
        opn = False
    else:
        if opn == False and c == 0:
            opn = True
        c += 1
print(mx)
print(count)