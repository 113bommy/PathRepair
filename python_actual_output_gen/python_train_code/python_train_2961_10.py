'''Author- Akshit Monga'''
t=int(input())
for _ in range(t):
    n=int(input())
    if n%4==0:
        print(n//4)
    elif n%4==1 and n>=9:
        print(n//4-1)
    elif n%4==2 and n>=6:
        print(n//4)
    elif n%4==3 and n>=15:
        print(n//4-2)
    else:
        print(-1)