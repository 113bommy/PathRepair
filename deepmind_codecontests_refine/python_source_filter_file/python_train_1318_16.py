n=input()

p=n.count('-')
q =n.count('o')

if p>=0 and q>0:
    if p%q==0:
        print('YES')
    else:
        print('NO')
if q==0:
    print('NO')
