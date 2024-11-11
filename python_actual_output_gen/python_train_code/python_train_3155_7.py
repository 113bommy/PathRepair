t=int(input())
for i in range(t):
    x1,y1,x2,y2=map(int,input().split())
    if x1==x2:
        print(max(y1,y2)-min(y1,y2))
    if y1==y2:
        print(max(x1,x2)-min(x1,x2))
    else:
        print(max(y1,y2)-min(y1,y2)+max(x1,x2)-min(x1,x2)+2)