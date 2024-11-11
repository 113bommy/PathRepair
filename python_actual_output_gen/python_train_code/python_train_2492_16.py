for _ in range(int(input())):
    a,b,x,y=map(int,input().split())
    print(max(a-x-1,x)*max(b-y-1,y))