a1 = input()
a2 = input()
b = 0
s = ''
for i in a1:
    if i == a2[b]:
        s += '0'
    elif i != a2[b]:
        s += '1'
    b += 1
print(int(s))