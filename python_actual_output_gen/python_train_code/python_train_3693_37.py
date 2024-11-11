n=int(input())
if(n==0):
    print('O-|_OOOO')
while(n!=0):
    a=n%10
    n=n//10
    if(a<5):
        print('0-|',end='')
        for i in range(a):
            print('0',end='')
        print('-',end='')    
        for i in range(4-a):
            print('0',end='')
    else:
        a=a-5
        print('-0|',end='')
        for i in range(a):
            print('0',end='')
        print('-',end='')    
        for i in range(4-a):
            print('0',end='')
    print('')
    