a= input()
b = input()
l = []
for i in range(len(a)):
    if not a[i] == b[i]:
        l.append(1)
    else:
        l.append(0)
for i in range(len(l)):
    print(l[i], end = ' ')