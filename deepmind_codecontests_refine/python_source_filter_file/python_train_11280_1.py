import math

n,m,k = [int(x) for x in input().split()]

week = n+m

if k == 1:
    things = []
    x = 1
    while x <= week:
        things.append(str(x))
        x += n-1
    print(len(things))
    print(' '.join(things))
        
else:
    things = ['1']
    x = 1

    while x <= week:
        things += [str(x)]*(k-1)
        x += n
        if x <= week:
            things.append(str(x-1))
    print(len(things))
    print(' '.join(things))
    
