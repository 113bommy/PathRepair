s = input()
n = n1 = n2 = 0
for i in range(0, len(s), 2):
    if s[i] == '1':
        n += 1
    elif s[i] == '2':
        n1 += 1
    else:
        n2 += 1
ss = "1+" * n + "2+" * n2 + "3+" * n2
print(ss[:-1])
