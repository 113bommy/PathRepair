n=int(input())
a=list(map(int,input().split()))
for i in range(n):
    a=sorted(a)
    a.reverse()
    for j in range(n-1):
        if(a[j]>a[j+1]):
            a[j]-=a[j+1]
print(sum(a))
