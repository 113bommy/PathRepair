for _ in range(int(input())):
    n=int(input())
    if n<4 or (n==5 or n==7 or n==11):
        print(-1)
        continue
    r=n%4
    if r==1:
        print((n-9)//4+1)
    elif r==3:
        print((n-15)//4+2)
    else:
        print(n//4)
        