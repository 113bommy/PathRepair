for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    d={}
    for i in range(n):
        p=(i+1)+a[(i+1)%n]
        if p not in d:
            d[p]=i
    k=[*d.values()]
    k.sort()
    f=[]
    for i in range(n):
        f.append(i)
    if(f!=k):
        print("NO")
    else:
        print("YES")