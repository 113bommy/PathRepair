n,m,z=input().split()
n,m,z=int(n),int(m),int(z)
a=n
b=m
if n==m:
    print(int(z/n))
elif n<m:
    count =0
    count=int(count)
    while n<z:
        n+=a
        if n<z:
         if n%m==0:
            count+=1
    print(count)

else:
    count = 0
    while m < z:
        m += b
        if m<z:
         if m % n == 0:
            count += 1
    print(count)