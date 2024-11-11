a,b,c = input().split()
a=int(a)
b=int(b)
c=int(c)
if a>b:
    if a<(b+c):
        print('?')
    else:
        print('+')
    
elif b>a:
    if b<(a+c):
        print('?')
    else:
        print('-')
elif a==b:
    if c>0:
        print('?')
    else:
        print('0')
