n,d=map(int,(input().split()))

x=list(map(int,input().split()))


count=2

if n>1:
    for i in range(1,n):
        temp=x[i]-x[i-1]
        if temp==(2*d):
            count=count+1
        if temp>2*d:
            count=count+2

print(count)