import math

t = int(input())
for _ in range(t):
    k = int(input())
    if k==2:
        print("1 2")

    else:
        temp = int(math.sqrt(k))
        k -= temp**2
        if k==0:
            print(f'{temp} {1}')
        elif k<temp+1:
            print(f'{k} {temp+1}')
        else:
            print(f'{temp+1} {min(k,(2*temp+2-k))}')