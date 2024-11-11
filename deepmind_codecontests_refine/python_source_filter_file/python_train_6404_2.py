b = input()
a = input()
l = []
for i in range(len(b)):
    if a[i] == b[i]:
        l.append("0")
    else:
        l.append("1")
print(int("".join(l)))
    