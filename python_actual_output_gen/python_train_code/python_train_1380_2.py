n,w = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
minGirl = a[0]
minBoy = a[n]
x = min(minGirl,minBoy/2)
print(max(w,3*x*n))
