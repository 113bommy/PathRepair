for _ in range(int(input())):
    d=int(input())
    if(d==0):
        print('Y %1.7f %1.7f'%(0,0))
    else:
        D=d**2-4*d
        if(D<0):
            print('N')
        else:
            a=(d+D**(1/2))/2
            print('Y %1.8f %1.8f'%(a,d/a))