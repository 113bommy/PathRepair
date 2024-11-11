n,k=map(int,input().split())
a=list(map(int,input().split()))
c=[]
for i in range(k):
    print(a[i],end=' ')
    l=1
    for j in range(n*k+1):
        if j not in a and j not in c and l<n:
            print(j,end=' ')
            l+=1
            c.append(j)
        if l>=n:
            #print(l)
            l=1
            break
    print()