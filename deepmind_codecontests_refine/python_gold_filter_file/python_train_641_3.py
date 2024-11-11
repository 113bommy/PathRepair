
a,b,c,d = sorted(list(map(int, input().split())))
if(a+d==b+c or a+b+c==d):
    print('YES')
else:
    print('NO')
