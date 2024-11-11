n=int(input())
a=list(map(int,input().split()))
a.sort()
s=sum(a)
x=0
y=0
i=0
j=n-1
while i<j:
    x+=a[j]
    y+=a[i]
    j-=1
    i+=1
if n%2==0:
    print(x**2+y**2)
else:
    x+=a[n//2]
    print(x**2+y**2)