x1,y1,x2,y2=map(int,input().split())

k1=x2-x1
k2=y2-y1

print(x2-k2,y2+k1,x2-k2-k1,y2+k1-k2)