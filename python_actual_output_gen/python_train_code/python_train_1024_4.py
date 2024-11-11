t=int(input())
for i in range(t):
    n=int(input())
    if n==1 or n==2:
        print(1)
    elif n==3:
        print(2)
    else:
        print(n//2)