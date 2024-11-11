f=lambda:map(int,input().split())
t,s,x=f()
if x<t:
    print('NO')
elif t<=x<t+s:
    print('YNEOS'[x!=t::2])
else:
    print('YES' if (x-t)%s in [0,1] else 'NO')