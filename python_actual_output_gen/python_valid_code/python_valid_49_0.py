i=int(input())
for x in range(i):
    n,k=input("").split()
    n=int(n);k=int(k)
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    for x in range(n):
        for y in range(n-x):
            if y+1<n:
                if a[y] > a[y+1]:
                    temp=a[y]
                    a[y]=a[y+1]
                    a[y+1]=temp
    for x in range(n):
        for y in range(n-x):
            if y+1<n:
                if b[y] > b[y+1]:
                    temp=b[y]
                    b[y]=b[y+1]
                    b[y+1]=temp
    for z in range(k):
        if(a[z]>b[n-1-z]):
            a[z]=b[n-1-z]
    print(sum(a))
