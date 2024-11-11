
import math
N = int(input())
XY = [list(map(int,input().split())) for _ in  range(N)]
for i in range(N):
    XY[i].append(math.atan2(XY[i][1],XY[i][0]))

XY.sort(key = lambda x:x[2])
ans = 0
tmp = [0,0]
ruisekiwa_x = [0] * N
ruisekiwa_y = [0] * N
ruisekiwa_x[0] = XY[0][0]
ruisekiwa_y[0] = XY[0][1]

for i in range(1,N):
    ruisekiwa_x[i] = ruisekiwa_x[i-1] + XY[i][0]
    ruisekiwa_y[i] = ruisekiwa_y[i-1] + XY[i][1]
    
ans = 0
for i in range(N):
    for j in range(i,N):
        if i>0: 
            tmp[0] = ruisekiwa_x[j] - ruisekiwa_x[i-1]
            tmp[1] = ruisekiwa_y[j] - ruisekiwa_y[i-1]
        else:
            tmp[0] = ruisekiwa_x[j] 
            tmp[1] = ruisekiwa_y[j] 
            
            
        ans = max(ans,math.sqrt(tmp[0]*tmp[0] + tmp[1]*tmp[1]))
for i in range(N):
    if XY[i][2] < 0:
        XY[i][2] = -math.pi-XY[i][2]
    else:
        XY[i][2] = math.pi - XY[i][2]
        

XY.sort(key = lambda x:x[2])
ruisekiwa_x = [0] * N
ruisekiwa_y = [0] * N
ruisekiwa_x[0] = XY[0][0]
ruisekiwa_y[0] = XY[0][1]

for i in range(1,N):
    ruisekiwa_x[i] = ruisekiwa_x[i-1] + XY[i][0]
    ruisekiwa_y[i] = ruisekiwa_y[i-1] + XY[i][1]
    
for i in range(N):
    for j in range(i,N):
        if i>0: 
            tmp[0] = ruisekiwa_x[j] - ruisekiwa_x[i-1]
            tmp[1] = ruisekiwa_y[j] - ruisekiwa_y[i-1]
        else:
            tmp[0] = ruisekiwa_x[j] 
            tmp[1] = ruisekiwa_y[j] 
            
            
        ans = max(ans,math.sqrt(tmp[0]*tmp[0] + tmp[1]*tmp[1]))
        
print(ans)

