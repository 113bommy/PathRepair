n = int(input())
s = []
for i in range(n):
    s.append(input())
for i in range(n):
    if s[i][0] == s[i][1] == 'O':
        s[i] = '++'+s[i][2:]
        print('YES')
        print('\n'.join(s))
        break
    if s[i][3] == s[i][4] == 'O':
        s[i] = s[1][:3]+'++'
        print('YES')
        print('\n'.join(s))
        break
else:
    print('NO')