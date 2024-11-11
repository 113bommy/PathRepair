for _ in range(int(input())):
    a,b=map(int,input().split())
    n=a%b
    if(n==0):
        print(n)
    else:
        print(b-n)