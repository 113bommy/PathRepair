t=int(input())
for q in range(t):
    a,b,c,d=map(int,input().split())
    if (a+b)%2==1:
        if a>0 or d>0:
            print('Ya',end=' ')
        else:
            print('Tidak',end=' ')
        if b>0 or c>0:
            print('Ya',end=' ')
        else:
            print('Tidak',end=' ')
        print('Tidak Tidak')
    if (a+b)%2==0:
        print('Tidak Tidak',end=' ')
        if b>0 or c>0:
            print('Ya',end=' ')
        else:
            print('Tidak',end=' ')
        if a>0 or d>0:
            print('Ya')
        else:
            print('Tidak')