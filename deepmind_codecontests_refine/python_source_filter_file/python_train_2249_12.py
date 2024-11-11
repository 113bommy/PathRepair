nandm = [int(i) for i in input().split()]
n = nandm[0]
m = nandm[1]
b = []
numB = 0
for i in range(n):
    string = list(input())
    for j in range(len(string)):
        if string[j]=="B":
            b.append((j, n-i-1))
            numB+=1
#print(b)
maxx = -1
maxy = -1
minx = m+1
miny = n+1
for x in b:
    if x[0]>maxx:
        maxx = x[0]
    if x[0]<minx:
        minx = x[0]
    if x[1]>maxy:
        maxy = x[1]
    if x[1]<miny:
        miny = x[1]
#print(maxx, maxy, minx, miny)
side = max(maxx-minx, maxy-miny)+1
if numB==0 or numB==1:
    print(1-numB)
elif side<n and side<m:
    print(side*side-numB)
else:
    print(-1)