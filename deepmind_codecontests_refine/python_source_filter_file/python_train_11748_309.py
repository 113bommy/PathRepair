x,a,b = map(int,input().split())
if a>b:
    print('delicious')
elif b-a>x:
    print('dangerous')

else:
    print('safe')