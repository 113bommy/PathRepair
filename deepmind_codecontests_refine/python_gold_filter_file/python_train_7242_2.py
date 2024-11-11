s = input()
a = ['B', 'u', 'l', 'b', 'a', 's', 'r']
b = []
for i in range(len(a)):
    if a[i] != 'a' and a[i] != 'u':
        b.append(s.count(a[i]))
    else:
        b.append(int(s.count(a[i])/2))
print(min(b))