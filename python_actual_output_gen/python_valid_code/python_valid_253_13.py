n = int(input())
s = ''

for i in range(n):
    x = input()
    if s.count('++')>0 or x.count('OO') == 0:
        s += x + '\n'
    else:
        x.replace('OO', '++')
        s += x + '\n'
if s.count('++')>0:
    print("YES")
    print(s)
else:
    print('NO')