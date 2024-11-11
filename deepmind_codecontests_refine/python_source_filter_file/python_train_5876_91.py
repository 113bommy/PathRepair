s = list(input())
t = list(input())
t.reverse()
if((''.join(s)) == (''.join(t))):
    print('Yes')
else:
    print('NO')