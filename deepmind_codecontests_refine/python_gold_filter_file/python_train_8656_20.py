t=int(input())
for j in range(t):
    n=int(input())
    stri=list(input())
    try:
        c=stri.index('8')
        if n-c>=11:
            print('YES')
        else:
            print('NO')
    except ValueError:
        print('NO')
