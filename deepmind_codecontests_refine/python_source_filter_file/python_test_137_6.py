x,y=[str(bin(int(i)))[2:] for i in input().split()]

if x==y:
    print('YES')
elif y[-1]=='0':
    print('NO')
else:
    x+='1'
    if (y.find(x)!=-1 or y.find(x[:-1])!=-1) and y.count('1')-x.count('1')==len(y)-len(x):
        print('YES')
    else:
        x=x[:-1]
        while x[-1]=='0':
            x=x[:-1]
        print('YES') if (y.find(x)!=-1 or y.find(x[::-1])!=-1) and y.count('1')-x.count('1')==len(y)-len(x) else print('NO')