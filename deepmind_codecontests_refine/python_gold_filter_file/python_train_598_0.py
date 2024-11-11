n=int(input())
a=[float('Inf')]
a+=list(map(int,input().split()))
i=0
m=1000
while i<n:
    if a[i]>a[i+1]:
        s=a[i+1]
    if a[i]<a[i+1]:
        m=m//s*a[i+1]+m%s
        s=a[i+1]
    i+=1
print(m)