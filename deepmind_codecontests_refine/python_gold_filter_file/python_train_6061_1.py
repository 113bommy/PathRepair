for i in range(int(input())):
    n =int(input())
    
    if n%2==0:
        n=n//2
        ls=['1']*n
        print(''.join(map(str,ls)))
    else:
        print('7',end='')
        n=n-3
        n=n//2
        ls=['1']*n
        print(''.join(map(str,ls)))