n=int(input())
a=list(map(int,input().split()))
c=sum(a)
b=[]
d=0
e=n
for i in range(n):
    d+=a[i]
    b.append(c-2*d)
for i in range(n):
    if n%2==0:
        if b[i]<0:
            e=i
            break
    else:
        if b[i]+a[i]<0:
            e=i
            break
print(e,n-e)