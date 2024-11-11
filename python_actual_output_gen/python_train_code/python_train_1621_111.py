n=int(input())
a=list(map(int,input().split()))
a=sort(a)
print(a[n/2+1]-a[n/2])
