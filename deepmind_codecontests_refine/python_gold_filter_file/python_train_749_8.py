a = input()
s1 = []
s2 = []
c, o = 0, len(a) - 1
while (o - c) >= 1:
    while o >= 0 and a[o] == "(":
        o -= 1
    while c < len(a) and a[c] == ")":
        c += 1
    if o >= 0 and c < len(a) and c < o:
        s1.append(c + 1)
        s2.append(o + 1)
        c += 1
        o -= 1
if not s1:
    print(0)
    exit(0)
print(1)
print(2 * len(s1))
print(*s1, end=" ")
s2.reverse()
print(*s2)
