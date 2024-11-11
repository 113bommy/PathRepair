x, y = map(int, input().split())
c=2
while True:
    if c%2==0:
        if x>=2 and y>=2:
            c=c+1
            x=x-2
            y=y-2
            continue
        elif x>=1 and y>=12:
            c=c+1
            x=x-1
            y=y-12
            continue
        elif x>=0 and y>=22:
            c=c+1
            y=y-22
            continue
        else:
            print("Hanako")
            break
    if c%2==1:
        if x>=0 and y>=22:
            c=c+1
            y=y-22
            continue
        elif x>=2 and y>=2:
            c=c+1
            x=x-2
            y=y-2
            continue
        elif x>=1 and y>=12:
            c=c+1
            x=x-1
            y=y-12
            continue
        else:
            print("Ciel")
            break