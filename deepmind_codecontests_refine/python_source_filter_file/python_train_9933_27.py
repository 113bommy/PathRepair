x, y=map(int,input().split())
l=list(map(int,input().split()))
winsum=0
for i in range(y):
    winsum+=l[i]
minsum=winsum
h=1
if x>y:
    for j in range(x-y):
        winsum=winsum-l[i]+l[i+y]
        if winsum<minsum:
            minsum=winsum
            h=j+2
print(h)