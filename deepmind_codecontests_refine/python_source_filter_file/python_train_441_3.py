for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    c = list(map(int,input().split()))
    i=1
    j=0
    fin = [a[0]]
    while i<n:
        if a[i]!=a[i-1]: fin.append(a[i])
        else:
            if b[i]!=fin[-1]: fin.append(b[i])
            else: fin.append(c[i])
        i+=1
    if fin[0]==fin[n-1]:
        if b[n-1]!=fin[0] and fin[n-2]!=b[n-1]: fin[n-1]=b[n-1]
        elif c[n-1]!=fin[0] and fin[n-2]!=c[n-1]: fin[n-1]=c[n-1]
        elif a[n-1]!=fin[0] and fin[n-2]!=a[n-1]: fin[n-1]=a[n-1]
        elif fin[n-1]!=b[0] and b[0]!=fin[1]: fin[0]=b[0]
        elif fin[n-1]!=a[0] and a[0]!=fin[1]: fin[0]=a[0]
        elif fin[n-1]!=c[0] and c[0]!=fin[1]: fin[0]=c[0]

        
    for i in fin:
        print(i,end=" ")
    print()


    
        
