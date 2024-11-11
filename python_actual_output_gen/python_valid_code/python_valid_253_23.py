n = int(input())
s = [input() for i in range(n)]
ans = 0
for i, item in enumerate(s):
    if 'OO' in item:
        s[i] = s[i].replace('OO', '++')
        ans = 1
        break

if ans == 1:
    print('YES')
    print(*s, sep = '\n')
else:
    print('NO')

##print(*s, sep = '\n')
