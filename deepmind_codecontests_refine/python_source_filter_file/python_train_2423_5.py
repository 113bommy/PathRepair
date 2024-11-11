
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=[]
    for i in range(0,n-1,2): 
        if a[i]<0 and a[i+1]<0:
            b.append(abs(a[i+1]))
            b.append(abs(a[i]))
        elif a[i]<0 and a[i+1]>0:
            b.append(a[i+1])
            b.append(abs(a[i]))
        elif a[i]>0 and a[i+1]>0:
            b.append(0-a[i+1])
            b.append(a[i])
        elif a[i]>0 and a[i+1]<0:
            b.append(abs(a[i+1]))
            b.append(a[i])
    print(*b)        
            