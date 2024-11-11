for _ in range(int(input())):
    n=int(input())
    if n%4==0:
        b=((n//4)-1)
        print('9'*(n-b)+'8'*b)
    else:
        b=(n//4)
        print('9'*(n-b)+'8'*b)