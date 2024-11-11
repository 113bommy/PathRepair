for _ in range(int(input())):
    n,x=map(int,input().split())
    print( (n-3)//x+2 if n>3 else 1)