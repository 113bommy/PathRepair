b=int(input())
for i in range(b):
    c=int(input())
    d=list(map(int,input().split()))
    x1=[0,0,0]
    for j in d:
        x1[(j%3)]=x1[(j%3)]+ 1
    s=(x1[0]+min(x1[1],x1[2]))
    if x1[1]>x1[2]:
        print(s+(x1[1]-x1[2])//3)
    else:
        print(s+(x1[1]-x1[2])//3)