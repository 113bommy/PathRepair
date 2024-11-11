x1,x2=map(int,input().split())
y1,y2=map(int,input().split())
if x1==x2:
    print(2*(1+abs(y1-y2)+2))
elif y1==y2:
    print(2*(1+abs(x1-x2)+2))
else:
    print(2*(abs(x1-x2)+1+abs(y1-y2)+1))