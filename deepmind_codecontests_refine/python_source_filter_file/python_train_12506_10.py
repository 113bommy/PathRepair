q=int(input())
for i in range(0,q):
    n=int(input())
    s=str(input())
    if n==2:
        if s[0]>s[1]:
            print('YES')
            print(2)
            print(s[0],s[1])
        else:
            print('NO')
    else:
        print('YES')
        print(2)
        print(s[0],s[1:])
