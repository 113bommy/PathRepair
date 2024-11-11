def findAns():
    t=int(input())
    for i in range(t):
        l,r=map(int,input().split())
        if l<=(r-1)//2:
            print((r-1)//2)
        else:
            print(r%l)
findAns()

