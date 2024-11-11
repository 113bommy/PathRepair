n = int(input())
a = list(map(int,input().split()))
minm = 1000000
maxm = 0
for i in range(1,len(a) - 1):
    diff = a[i + 1] - a[i - 1]
    if diff < minm:
        minm = diff
for i in range(2,len(a) - 1):
    d = a[i] - a[i-1]
    if d > maxm:
        maxm = d
        
if len(a) == 3:
    print(a[2] - a[0])
else:
    print(max(minm,maxm))
