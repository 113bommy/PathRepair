t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    if '8' not in s:
        print('NO')
    else:
        x=s.index('8')
        if n-x>=11:
            print('YES')
        else:
            print('NO')