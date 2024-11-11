for _ in range(int(input())):
    a,b,x,y=map(int,input().split())
    print(max(max(a-x,x-1)*b,max(b-y,y-1)*a))