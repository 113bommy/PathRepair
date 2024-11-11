try:
    t=int(input())
    for i in range(0,t):
        w=[]
        n,m=list(map(int,input().split(" ")))
        k=list(map(int,input().split(" ")))
        s=sum(k)
        if s>=m:
            print(m)
        elif s<m:
            print(s)
except:
    pass