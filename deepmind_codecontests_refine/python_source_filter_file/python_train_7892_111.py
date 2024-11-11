a = list(map(int,input().split())).sort()
k = int(input())
print(a[0]+a[1]+a[2]*(2**k))