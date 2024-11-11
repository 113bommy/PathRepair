n=int(input())
a=list( map(int, input().split()))
if n<3:
    print(0)
    exit()
a.sort()
mn=a.count(a[0])
mx=a.count(a[n-1])
print(n-mx-mn)



