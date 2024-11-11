for t in range(int(input())):
    n, d=[int(i) for i in input().split()]
    l=[int(i) for i in input().split()]
    i=1
    k=l[0]
    while d>i and i<n:
        if l[i]>0:
            l[i]-=1
            k+=1
            d-=(i)
        else:
            i+=1
    print(k)