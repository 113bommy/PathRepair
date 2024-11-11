t = int(input())
names = []
for i in range(t):
    names.append(input())
print('NO')
for i in range(1, len(names)):
    if names[i] in names[:i-1]:
        print('YES')
    else:
        print('NO')