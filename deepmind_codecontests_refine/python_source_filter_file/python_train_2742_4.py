def check(ponits):
    d1 = ((points[0] - points[2]) ** 2) + ((points[1] - points[3]) ** 2)
    d2 = ((points[0] - points[4]) ** 2) + ((points[1] - points[5]) ** 2)
    d3 = ((points[4] - points[2]) ** 2) + ((points[5] - points[3]) ** 2)
    if (d1 + d2 == d3 or d1 + d3 == d2 or d2 + d3 == d1) and d1 != d2 and d1 != d3 and d3 != d2:
        return True
    return False
points = list(map(int, input().split()))
# (0,1) (2,3) (4,5)
if(check(points)):
    print("RIGHT")
    exit()
dx = [0,1,0,-1]
dy = [1,0,-1,0]
for j in range(0,6,2):
    for i in range(4):
        points[j]+=dx[i]
        points[j+1]+=dy[i]
        if(check(points)):
            print("ALMOST")
            exit()
        points[j]-=dx[i]
        points[j+1]-=dy[i]
print("NEITHER")

