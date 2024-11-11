for tt in range(int(input())):
    a,b,c=map(int,input().split())
    print(max(0,(abs(a-c)+abs(a-b)+abs(b-c))))