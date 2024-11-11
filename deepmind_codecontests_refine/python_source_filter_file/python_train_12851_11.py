import math
n,m = map(int,input().split())
l = list(map(int,input().split()))


lastIndex = None

for i in range(n):
    if l[i] > m:
        if lastIndex == None:
            lastIndex = i
        if math.ceil(l[i]//m) >= math.ceil(l[lastIndex]//m):
            lastIndex = i

if lastIndex == None:
    print(n)
else:
    print(lastIndex + 1 )

            