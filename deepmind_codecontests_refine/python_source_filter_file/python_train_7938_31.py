n,m,x,y = map(int,input().split(' '))
for i in range(y,m+1):
    print(x,i)
i = y-1
while i>=1:
    print(x,i)
    i = i - 1
e = False
for i in range(1,m+1):
    arr = []
    for j in range(1,n+1):
        if j!=x:
            arr.append([i,j])
    if e == False:
        for item in arr:
            print(item[0],item[1])
        e = True
    else:
        arr.reverse()
        for item in arr:
            print(item[0],item[1])
        e = False