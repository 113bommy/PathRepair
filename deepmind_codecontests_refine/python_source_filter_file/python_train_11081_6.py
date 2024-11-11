a = len(input())-2
b = len(input())-2
c = len(input())-2
d = len(input())-2
l = list()
l.append(a)
l.append(b)
l.append(c)
l.append(d)
l = sorted(l)
one, two = 0, 0
if l[0] <= l[1]//2 and l[0] <= l[2]//2 and l[0] <= l[3]//2:
    one = 1
if l[3] >= l[0]*2 and l[3] >= l[1]*2 and l[3] >= l[2]*2:
    two = 1
if one+two == 1:
    if one == 1:
        if l[0] == c:
            print("C")
        elif l[0] == a:
            print("A")
        elif l[0] == b:
            print("B")
        else:
            print("D")
    if two == 1:
        if l[3] == c:
            print("C")
        elif l[3] == a:
            print("A")
        elif l[3] == b:
            print("B")
        else:
            print("C")
else:
    print("C")