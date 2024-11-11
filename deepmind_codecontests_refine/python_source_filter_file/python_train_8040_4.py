for t in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    s=set()
    c=0
    for i in range(1,n+1):
        r=i+a[i%n]
        if r in s:
            c=1
            break
        else:
            s.add(r)
    if c==0:
        print("YES")
    else:
        print("NO")