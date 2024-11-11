for _ in range(int(input())):
    n,m=map(int,input().split())
    arr=[int(k) for k in input().split()]
    sumi=0
    for i in range(n):
        sumi=sumi+arr[i]
    if sumi>=m:
        print(m)
    else:
        print(sumi)