n=int(input())
if n%4==3:
    print(0)
    print((n-3)//4+2,end=' ')
    print(1,2,' '.join([str(i)+' '+str(i+3) for i in range(4,n-2,4)]))
elif n%4==0:
    print(0)
    print(n//2,end=' ')
    print(' '.join([str(i)+' '+str(i+3) for i in range(1,n-2,4)]))
elif n%4==1:
    print(1)
    print(n//2+1,end=' ')
    print(1,' '.join([str(i)+' '+str(i+3) for i in range(2,n-2,4)]))
elif n%4==2:
    print(1)
    print(n//2,end=' ')
    print(1,' '.join([str(i)+' '+str(i+3) for i in range(3,n-2,4)]))