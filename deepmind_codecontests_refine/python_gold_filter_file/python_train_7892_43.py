a = list(map(int,input().split()))
d = int(input())
a.sort()
print(a[0]+a[1]+a[2]*2**d)