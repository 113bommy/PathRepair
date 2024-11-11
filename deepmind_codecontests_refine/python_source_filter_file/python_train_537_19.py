for i in range(int(input())):
    n,k,d=map(int,input().split())
    mass=[int(i) for i in input().split()]
    mi=100000000000
    for j in range(n-d+1):
        q=len(set(mass[j:j+d+1]))
        if mi>q:
            mi=q
    print(mi)