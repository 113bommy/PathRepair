x1,y1,x2,y2 = map(int,input().split())
k = abs(y2-y1)
m = x2-x1
print(x2-k,y2+m,x1-k,y1+m)