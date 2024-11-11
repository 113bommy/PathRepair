s = input()
c = 0
for i in s:
    if i in ('a', 'e', 'i', 'o', 'u'):
        c += 1
    elif i in ('0', '2', '4', '6', '8'):
        c += 1
print(c)
