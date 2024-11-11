a = input()
b = len(set(map(str, (a[1:-1]).split(", "))))
print(b)
if len(a) == 2:
    print('0')
else:
    print(b)