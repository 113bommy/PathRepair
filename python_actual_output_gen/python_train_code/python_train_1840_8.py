for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if a==b and b==c:
        print(1)
    else:
        print(min(b,c)+1)