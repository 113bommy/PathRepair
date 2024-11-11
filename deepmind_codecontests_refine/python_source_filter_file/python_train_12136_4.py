n=int(input())
z=list(input())
r=n*[0]
p=str()
m=0
g=0
for i in range(n):
    if n%2==0:
        if i%2==0:
            r[len(z)//2-1+m]=z[i]
            m+=1
        else:
            g+=1
            r[len(z)//2-1-g]=z[i]
    else:
        if i%2==0:
            r[len(z)//2+m]=z[i]
            m+=1
        else:
            g+=1
            r[len(z)//2-g]=z[i]
for i in range(len(r)):
    p+=r[i]
print(p)
