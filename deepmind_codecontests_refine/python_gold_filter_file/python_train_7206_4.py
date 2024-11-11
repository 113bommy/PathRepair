for t in range(int(input())):
    a,b,x,y=map(int,input().split())
    print(max(max(a-x-1,x)*b,max(y,b-y-1)*a))