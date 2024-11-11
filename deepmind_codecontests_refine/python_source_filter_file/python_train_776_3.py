n=int(input())
l=len(str(n))-1
k=int(str(n)[0:1])
a=[10**l]*k
n=n-k*(a[0])
while n>0:
    l=len(str(n))-1
    k=int(str(n)[0:1])
    b=10**l
    if k>len(a):
        z=k-len(a)
        for i in range(z):
            a.append(b)
            n=n-b
        for i in range(len(a)):
            if n>0:
                a[i]=a[i]+b
                n=n-b
    else:
        for i in range(k):
            a[i]=a[i]+b
        n=n-k*(b)
print(len(a))
print(*a)