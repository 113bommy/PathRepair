for _ in range(int(input())):
    n=int(input())
    a=list(input())
    d=0
    m=0
    for i in range(n):
        if(a[i]=='<'):
            d=d+1
        else:
            break
    for j in range(n-1,-1,-1):
        if(a[i]=='>'):
            m=m+1
        else:
            break
    print(min(m,d))