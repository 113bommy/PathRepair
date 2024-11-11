from sys import stdin,stdout
t=int(stdin.readline())
for _ in range(t):
    n=int(stdin.readline())
    d1={}
    l=[]
    d={}
    for i in range(n):
        l.append(list(map(int,stdin.readline().split()))[1:])
    for i in range(n):
        j=0
        if len(l[i])!=0:
            x=l[i][j]
            while x in d:
                j+=1
                if j<len(l[i]):
                    x=l[i][j]
                else:
                    break
            d[x]=1
            if j<len(l[i]):
                d1[i+1]=1
    if len(d)==n:
        print("OPTIMAL")
    else:
        print("IMPROVE")
        for i in range(n):
            if i+1 not in d1:
                a=i+1
                break
        for i in range(n):
            if i+1 not in d:
                b=i+1
                break
    print(a,b)