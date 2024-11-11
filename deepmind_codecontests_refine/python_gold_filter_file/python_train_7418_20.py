t = int(input())
for cases in range(t):
    n = int(input())
    if n>30:
        print('YES')
        if n!=44 and n!=36 and n!=40:
            print(6,end=' ')
            print(14,end=' ')
            print(10,end=' ')
            print(n-30)
        elif n==36 or n==44 or n==40:
            print(6,end=' ')
            print(15,end=' ')
            print(10,end=' ')
            print(n-31)
    else:
        print('NO')