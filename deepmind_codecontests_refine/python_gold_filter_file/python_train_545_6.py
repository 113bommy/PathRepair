# Will it be easy? No. Will it be worth it? Absolutely. Unknown

n=int(input())
a=list(map(int,input().split()))
if n<4:
    if n==1:
        print(1,1)
        print(-a[0])
        print(1,1)
        print(0)
        print(1,1)
        print(0)
    elif n==2:
        print(1,1)
        print(-a[0])
        print(2,2)
        print(-a[1])
        print(2,2)
        print(0)
    else:
        print(1,1)
        print(-a[0])
        print(2,2)
        print(-a[1])
        print(3,3)
        print(-a[2])
    exit()
h1=1
h2=n-1

ah1=[0]*h1
ah2=[0]*h2
i=0
while i<h1:
    ah1[(i*n)%h1]=i*n
    i+=1

i=0
while i<h2:
    ah2[(i*n)%h2]=i*n
    i+=1

print(1,h1)
i=0
while i<h1:
    print(ah1[a[i]%h1]-a[i],end=" ")
    a[i]=ah1[a[i]%h1]
    i+=1
print()
print(h1+1,n)

while i<n:
    print(ah2[a[i]%h2]-a[i],end=" ")
    a[i]=ah2[a[i]%h2]
    i+=1
print()
print(1,n)
i=0
while i<n:
    print(-a[i],end=" ")
    i+=1
print()
