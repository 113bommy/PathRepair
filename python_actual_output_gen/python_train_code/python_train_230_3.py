
a,b,c,d = sorted(list(map(int, input().split())))
if(a+c==b+d or a+b+c==d):
    print('YES')
else:
    print('NO')
