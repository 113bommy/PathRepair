while True:
    points = list(map(int,input().split()))
    if points==[-1,-1,-1]: break
    sum_pt = sum(points[0:2])
    if points[0]==-1 or points[1]==-1 or sum_pt<30: print('F')
    elif sum_pt<50 and point[2]<50: print('D')
    elif sum_pt<65: print('C')
    elif sum_pt<80: print('B')
    else: print('A')