n=int(input())
for i in range(n):
    points = input().split()
    p = list(map(float,points))
    if (p[3]-p[0])**2 + (p[4]-p[1])**2 <= (p[2]-p[5])**2:
        if p[5]>p[2]:
            print(-2)
        else:
            print(2)
    elif (p[0]-p[3])**2 + (p[1]-p[4])**2 > (p[2]-p[5])**2 and (p[0]-p[3])**2 + (p[1]-p[4])**2 <= (p[2]+p[5])**2:
        print(1)
    else:
        print(0)