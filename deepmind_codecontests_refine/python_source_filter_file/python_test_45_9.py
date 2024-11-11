

n=int(input())
for i in range(n):
    m= int(input())
    p=1
    ara=[int(i) for i in input().split()]
    z=-1
    for k in range(m):
        if z==-1 and ara[k]==1:
            z=1
            p+=1
        elif ara[k] == 1 and ara[k-1] == 0:
            p+=1
        elif ara[k] == 0 and ara[k-1] == 1 and k!=1:
            p+=0
        elif ara[k] == 1 and ara[k-1] == 1:
            p+=5
        elif ara[k] == 0 and ara[k-1] == 0:
            p=-1
            break
    print(p)