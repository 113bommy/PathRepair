n,d=input().split(" ")
n=int(n)
d=int(d)
c=0
a=input().split(" ")
for i in range(n):
    a[i]=int(a[i])
k=sum(a)
r=(d-k-(n-1)*10)
if r>0:

    if r>=5:
        c=r//5
    print((n-1)*2+c)
else:
    print("-1")