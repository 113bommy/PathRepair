a = input()
b = set()
for i in range(len(a)):
    s = a[i:] + a[:i]
    b.add(s)
print(len(a))


