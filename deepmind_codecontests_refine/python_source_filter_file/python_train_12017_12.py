s = input()
s0,s3 = s.split('=')
s1,s2 = s0.split('+')
a = len(s1)
b = len(s2)
c = len(s3)

if a+b==c:
    print(s)

elif a+b+2==c:
    if c>1:
        print(str(a*'|')+'+'+str((b+1)*'|')+'='+str((c-1)*'|'))
    else:
        print('Impossible')

elif a+b==c+2:
    if b>1:
        print(str(a*'|')+'+'+str((b-1)*'|')+'='+str((c-1)*'|'))
    elif a>1:
        print(str((a-1)*'|')+'+'+str(b*'|')+'='+str((c-1)*'|'))
    else:
        print('Impossible')

else:
    print('Impossible')
