s = ''.join(input() for _ in range(4))
ans = False
for i in range(9):
    if (i+1)%4:
        S = (s[i]+s[i+1]+s[i+4]+s[i+5])
        if S.count('.') >= 3 or S.count('#') >=3 :
            print('YES')
            ans = True
            break
if not ans:
    print('NO')