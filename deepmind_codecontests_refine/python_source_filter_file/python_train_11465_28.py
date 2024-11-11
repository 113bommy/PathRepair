import math
for i in range(int(input())):
    d=int(input())
    D=d*d-4*d
    if D<0:
        print('N')
    else:
        a=(d+math.sqrt(D))/2
        b=(d-math.sqrt(D))/2
        print('Y','%.6f'%a,'%.6f'%b,sep=' ')
