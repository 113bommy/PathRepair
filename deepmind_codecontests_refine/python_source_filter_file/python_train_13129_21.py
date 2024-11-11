import math
#  lst = list(map(str, input().strip().split(' ')))
t=int(input())
for i in range(t):
    n,x,y,d = map(int, input().strip().split(' '))
    if y==x:
        print(0)
    else:
        if abs((y-x))%d==0:
            print(abs(y-x)//d)
        else:
            if (y-1)%d!=0 and (n-y)%d!=0:
                print('-1')
            elif (y-1)%d!=0:
                k = math.ceil((n-y)/d) + math.ceil((n-x)/d)
                print(k)
            elif (n-y)%d!=0:
                k = math.ceil((y-1)/d) + math.ceil((x-1)/d)
                print(k)
            else:
                k=max(math.ceil((n-y)/d) + math.ceil((n-x)/d),math.ceil((y-1)/d) + math.ceil((x-1)/d ))
                print(k)
    

