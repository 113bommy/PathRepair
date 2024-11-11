for i in range(int(input())):
    a,b,c,d = list(map(int,input().split()))
    print(max(a+b,c+d))