(x,y,a,b)=list(map(int,input().split()))
if b==y:
    print("0")
else:
    if a==b:
        initial=a+1
    elif b>a:
        initial=b+1
    else:
        initial=a
    arr=[]
    for i in range(initial,x+1):
        for j in range(b,min(y+1,i)):
            arr.append([i,j])
    arr.sort()
    print(len(arr))
    for i in range(len(arr)):
        print("%d %d"%(arr[i][0],arr[i][1]))