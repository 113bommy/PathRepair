from collections import defaultdict
n,l,x,y = map(int,input().split())
arr = [int(x) for x in input().split()]
d = defaultdict(bool)
for i in arr:
    d[i] = True
# check if already available
xs = False
ys = False
for i,v in enumerate(arr):
    if(d[v+x] or d[v-x]):
        xs = True
    if(d[v-y] or d[v+y]):
        ys = True
if(xs and ys):
    print(0)
elif(xs):
    print(1)
    print(y)
elif(ys):
    print(1)
    print(x)
else:
    # Try to add only one mark
    done = False
    a1,a2 = 0,0
    for i, v in enumerate(arr):
        plusY = v + y
        if(0<=plusY<=n):
            if(d[plusY-x]):
                a1,a2 = plusY,plusY-x
                done = True
                break
            if(d[plusY+x]):
                a1,a2 = plusY,plusY+x
                done = True
                break
        negY = v - y
        if(0<=negY<=n):
            if(d[negY-x]):
                a1,a2 = negY,negY-x
                done = True
                break
            if(d[negY+x]):
                a1,a2 = negY,negY+x
                done = True
                break
        plusX = v + x
        if(0<=plusX<=n):
            if(d[plusX-y]):
                a1,a2 = plusX,plusX-y
                done = True
                break
            if(d[plusX+y]):
                a1,a2 = plusX,plusX+y
                done = True
                break
        negX = v - x
        if(0<=negX<=n):
            if(d[negX-y]):
                a1,a2 = negX,negX-y
                done = True
                break
            if(d[negX+y]):
                a1,a2 = negX,negX+y
                done = True
                break
    if(done):
        print(1)
        print(a1)
    else:
        print(2)
        print(x,y)