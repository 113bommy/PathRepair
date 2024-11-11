n = int(input())
l = input().split()

z=0
for i in range(n):
    z=z+int(l[i])

c=0
for j in range(n):
    for k in range(j,n):
        b=0
        e=0
        for m in range(j,k):
            a=int(l[m])
            d=a
            if a==0:
                a=1
            else:
                a=0
            b=b+a
            e=e+d
        f=b-e
        if f>c:
            c=f
            
z=z+c
if c==0:
    z=z-1
print(z)
