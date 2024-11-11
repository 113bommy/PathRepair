testcases=int(input())
for j in range(testcases):
    #a is the size of x
    #b is the size of y
    values=list(map(int,input().split()))
    a=values[0]
    b=values[1]
    x=values[2]
    y=values[3]
    area1=0
    area2=0
    if x<=(a-x):
        area1=((a-x)-1)*b
    elif x>(a-x):
        area1=(x)*b
    if y<=(b-y):
        area2=((b-y)-1)*a
    elif y>(b-y):
        area2=(y)*a
    print(max(area1,area2))