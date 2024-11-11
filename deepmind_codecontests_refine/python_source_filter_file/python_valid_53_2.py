for _ in range(int(input())):
    n,k=map(int, input().split())
    li=list(map(int, input().split()))
    di={}
    a=1
    for i in sorted(li):
        di[i]=a
        a+=1
    changes=0
    i=0
    while i<n-1:
        while i<n-1 and di[li[i+1]]-di[li[i]]==1:
            i+=1
        if i!=n-1:
            changes+=1
        i+=1
    if changes<=k:
        print("Yes")
    else:
        print("No")