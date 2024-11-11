for _ in range(int(input())):
    a,b=map(int,input().split())
    print(max(a,b,2*min(a,b))**2)
