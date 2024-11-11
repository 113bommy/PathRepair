n=int(input())
MAX = 10000000000000
c=[]
for i in range(n):
    c.append(list(map(int,input().split())))
p=[]
m=int(input())
for i in range(m):
    p.append(list(map(int,input().split())))
maxval = 0
min2n = MAX
for i in range(n):
    if(c[i][1]<min2n):
        min2n = c[i][1]
max1m = 0
for i in range(m):
    if(p[i][0]>max1m):
        max1m = p[i][0]
if(max1m-min2n>maxval):
    maxval = max1m-min2n
max1n = 0
for i in range(n):
    if(c[i][0]>min2n):
        max1n = c[i][0]
min2m = MAX
for i in range(m):
    if(p[i][1]<min2m):
        min2m = p[i][1]
if(max1n-min2m>maxval):
    maxval = max1n-min2m
print(maxval)