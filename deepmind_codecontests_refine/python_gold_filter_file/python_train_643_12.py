n,sx,sy = map(int,input().split())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))
dir_u = 0
dir_d = 0
dir_r = 0
dir_l = 0
if sx!=0:
    for i in range(n):
        if arr[i][0]>sx and arr[i][1]>sy:
            dir_r+=1
            dir_u+=1
        if arr[i][0]==sx and arr[i][1]>=sy:
            dir_u+=1
        if arr[i][0]<sx and arr[i][1]<sy:
            dir_d+=1
            dir_l+=1
        if arr[i][0]==sx and arr[i][1]<=sy:
            dir_d+=1
        if arr[i][0]<sx and arr[i][1]>sy:
            dir_u+=1
            dir_l+=1
        if arr[i][0]<=sy and arr[i][1]==sy:
            dir_l+=1
        if arr[i][0]>sx and arr[i][1]<sy:
            dir_d+=1
            dir_r+=1
        if arr[i][0]>=sx and arr[i][1]==sy:
            dir_r+=1
    if dir_u>=dir_d and dir_u>=dir_l and dir_u>=dir_r:
        print(dir_u)
        print(sx,sy+1)
    elif dir_r>=dir_d and dir_r>=dir_l and dir_r>=dir_u:
        print(dir_r)
        print(sx+1,sy)
    elif dir_d>=dir_u and dir_d>=dir_l and dir_d>=dir_r:
        print(dir_d)
        print(sx,sy-1)
    else:
        print(dir_l)
        print(sx-1,sy)
    
    
