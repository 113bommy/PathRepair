n=int(input())
a=2
k=1
for i in range(1,n+1):
    b=i*i*(i+1)*(i+1)
    k=(b-a)/i
    a=i*(i+1)
    print (k)
