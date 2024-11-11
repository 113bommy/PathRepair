for _ in range(int(input())):
    n,s=map(int,input().split())
    a=list(map(int,input().split()))
    if sum(a)<=s: print(0); continue
    su=i=0
    while su<=s: su+=a[i]; i+=1
    print(a.index(max(a[:i]))+1)