n=int(input())
if n<=36:
    if n%2==0:
        print((n//2)*'8')
    else:
        print('6'+((n-1)//2)*'8')
else:
    print('-1')