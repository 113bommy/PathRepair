x=[int(i) for i in input().split()]
a=abs(x[0]-x[1])
if x[2]>a:
    print(int(sum(x)/2))
else:
    print((min([x[0],x[1]])+x[2])*2)
