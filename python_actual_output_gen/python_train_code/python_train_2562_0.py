for i in range(int(input())):
    n=int(input())
    if(n<=30):
        print('NO')
    else:
        print('YES')
        if(n-30==6 or n-30==10 or n-30==15):
            print(6,10,15,n-30-1)
        else:
            print(6,10,14,n-30)