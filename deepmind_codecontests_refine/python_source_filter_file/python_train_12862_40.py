n = int(input())
found = False
l = []
for _ in range(n):
    s = input().strip()
    if not found and s.find('OO') >= 0:
        s = s.replace('OO', '++')
        found = True
    l.append(s)

if found:
    print('YES')
    for i in l: print(i)
else:
    print('NO')

