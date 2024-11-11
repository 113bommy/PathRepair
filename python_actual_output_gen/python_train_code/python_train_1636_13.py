t = int(input())
while t>0:
    n = int(input())
    l = list(map(int, input().split()))
    print(l)
    s=[]
    for i in range(len(l)):
        for j in range(len(l)):
            if(i!=j):
                s.append(abs(l[i]-l[j]))
    print(min(s))
    t-=1