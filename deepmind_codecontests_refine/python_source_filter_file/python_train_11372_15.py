
import math

a ,b =map(int,input().split())

if a==b:
    if a==0:
        print(0)
    else:
        print(1)
        print(a)

else:
    if a>b:
        print(-1)
    else:
        if a==0:
            if b%2==0:
                print(2)
                print(b//2,b//2)
            else:
                print(-1)

        else:


            if (b-a)%2==0:
                if (((int((b-a)//2)) ^int(((b+a)//2))) == a):
                    print(2)
                    print((b-a)/2 ,(b+a)/2)
                else:
                    print(3)
                    print(a,(b-a)//2,(b-a)//2)
            else:
                print(-1)


