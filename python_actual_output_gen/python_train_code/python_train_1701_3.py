for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    a={}
    for i in range(n):
        a[l[i]] = i+1
    l.sort()
    c=0
    for i in range(n-1,0,-1):
        k=l[i]
        for j in range(n):
            if l[j] * k > 2*n-1:
                break
            if l[j] * k == a[l[i]] + a[k]:
                c+=1
    print(c)
                
            