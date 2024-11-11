a=list(map(int,input().split()))
k=int(input())
a.sort()
print(a[2]*k*2+a[1]+a[0])