a = input()
b = input()
c = ''
for i in range(len(a)):
    c = c + a[len(a)-i-1]
if c == b:
    print('YES')
else:
    print('NO')
