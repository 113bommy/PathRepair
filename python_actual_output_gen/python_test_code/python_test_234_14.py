n = input()

num = ['144', '14', '1']

for i in num:
    while i in n:
        n = n.replace(i, '0')

res = True
for i in n:
    if i != '0':
        res = False
        break

if res:
    print('YES')
else:
    print('NO')
