string = input()
s = string[0]
a = string[1]
n = int(input())
b = n%4
if s == '>':
    if a == '^':
        if b == 1:
            print("ccw")
        else:
            print("cw")
    elif a =='v':
        if b == 3:
            print("ccw")
        else:
            print("cw")
    else:
        print("undefined")
elif s == '<':
    if a == '^':
        if b == 1:
            print("cw")
        else:
            print("ccw")
    elif a =='v':
        if b == 3:
            print("cw")
        else:
            print("ccw")
    else:
        print("undefined")
elif s == '^':
    if a == '>':
        if b == 1:
            print("cw")
        else:
            print("ccw")
    elif a =='<':
        if b == 3:
            print("cw")
        else:
            print("ccw")
    else:
        print("undefined")
else:
    if a == '>':
        if b == 1:
            print("ccw")
        else:
            print("cw")
    elif a =='<':
        if b == 3:
            print("ccw")
        else:
            print("cw")
    else:
        print("undefined")
