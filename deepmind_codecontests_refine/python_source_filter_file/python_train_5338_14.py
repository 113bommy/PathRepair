n=int(input())
a=list(map(int,input().split()))
if n%2!=0:
    print(n//2)
    b=[]
    j=-1
    for i in range(n//2):
        b.append(a[j])
        j-=1
        b.append(a[i])
    b.append(a[n//2])
    print(*b)
    
else:
    print(n//2-1)
    b=[]
    j=-1
    for i in range(n//2):
        b.append(a[j])
        j-=1
        b.append(a[i])
    print(*b)    