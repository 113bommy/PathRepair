for _ in range(int(input())):
    a,b,x,y=map(int,input().split())
    print(max(max(a-x,x)*b,max(b-y,y)*a))