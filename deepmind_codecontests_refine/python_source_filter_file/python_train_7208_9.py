import math
for ad in range(int(input())):
    n,m,k = list(map(int, input().split()))

    if m<=(n//k):
        print(m)
    else:
        x=n//k

        if x>1:
            m -= x
            y=math.ceil(m/(x-1))

            print(x-y)
        else:
            if m>1:
                print(0)
            else:
                print(1)