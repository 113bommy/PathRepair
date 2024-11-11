num = int(input())

while(num>0):

    arr = list(map(int,input().split()))
    a = arr[0]
    b = arr[1]
    c = arr[2]
    r = arr[3]

    time = abs(b-a)
    lower = c-r
    upper = c+r
    if(time ==0):
        print(0)
        num-=1
        continue
    min_1 = min(a,b)
    max_1 = max(a,b)

    if(min_1<=lower):
        if(max_1>=upper and lower<max_1):
            time = time-upper+lower
        elif(max_1<upper and lower<max_1):
            time = time - max_1+lower
        else:
            time = time
    else:
        if(max_1>upper and min_1<=upper):
            time = time - upper+min_1
        elif(max_1>upper and min_1>upper):
            time=time
        else:
            time =0
    print(time)
    num-=1
