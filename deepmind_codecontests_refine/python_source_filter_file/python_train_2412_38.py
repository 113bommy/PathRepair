import math
def check(r):
    for x in range(1,int(math.sqrt(r-1))+2):
        if (r-1)%x==0:
            if (r-1)/x <x+1:
                print('NO')
                return
            if (r-1)/x >=x+1 and ((r-1)/x - (x+1))%2==0:
                print(x,end=" ")
                print(int(((r-1)/x - (x+1))/2))
                return
    print('NO')     
r=int(input())
check(r)