a=list(map(int,input().split()))
k=int(input())
a.sort()
print(a[0]+a[1]+a[2]*pow(2,k))