n,b,d=map(int,input().split())
a=[int(i) for i in input().split()]
k=h=0
for i in range(n):
    if(a[i]<=b):
        k+=a[i]
        if(k>d):
            k=0
            h+=1
print(h)