for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if a==b and a==c:
        print(1)
    else:
        print(a-min(b,c)+1)