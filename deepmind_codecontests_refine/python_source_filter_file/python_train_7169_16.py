count = int(input())
for i in range(count):
    x = list(map(float ,input().split()))
    x1=x[2]-x[0]
    y1=x[3]-x[1]
    x2=x[6]-x[4]
    y2=x[7]-x[5]
    if abs(x1*y2-x2*y1)<=0.00001:
        print("YES")
    else:
        print("NO")