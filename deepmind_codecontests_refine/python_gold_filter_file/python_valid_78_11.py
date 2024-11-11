def findAns():
    t=int(input())
    for i in range(t):
        l,r=map(int,input().split())
        if l<=(r)//2:
            print(r%(r//2+1))
        else:
            print(r%l)
findAns()

