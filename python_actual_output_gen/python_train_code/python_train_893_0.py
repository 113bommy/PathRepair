x1,y1,x2,y2=map(int,input().split())
diff=abs(x2-x1);diff1=abs(y2-y1)
if  x1!=x2 and y1!=y2 and (abs(x2-x1)!=abs(y2-1)):
    print(-1)
else:
    if abs(y2-y1) == 0:
        print(x1,y1+diff,x2,y2+diff)
    elif abs(x2-x1) == 0:
        print(x1+diff1,y1,x2+diff1,y2)
    else:
        print(x1,y2,x2,y1)