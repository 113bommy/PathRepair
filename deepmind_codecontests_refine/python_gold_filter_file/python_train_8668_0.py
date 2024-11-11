for _ in range(int(input())):
    x,y,k = map(int,input().split())
    print((k+k*y-3+x)//(x-1)+k)