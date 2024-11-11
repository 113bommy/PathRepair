x = list(map(int,input().split()))
x.sort()
if x[2] > x[0]+x[1]:
    print(x[2]-x[0]-x[1] + 1)
else:
    print(0)
    