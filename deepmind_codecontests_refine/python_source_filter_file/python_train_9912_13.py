for _ in " "*int(input()):
    n,s=map(int,input().split())
    a=list(map(int,input().split()))
    se,i,m,j=0,0,0,0
    while i<n and s>=a[i]+se:
        if a[i]>m:m=a[i];j=i
        se+=a[i];i+=1
    r=0;k=0;se1=se;i1=i+1;r1=0;p=i+1
    se-=m
    while i<n and s>=se+a[i]:r+=1;se+=a[i];i+=1
    while i1<n and s>=se1+a[i1]:r1+=1;se+=a[i1];i1+=1
    if r>r1:print(j+1)
    elif r1:print(p)
    else:print(0)