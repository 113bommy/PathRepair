w,a,b = map(int,input().split())
print(0 if  abs(a-b)-w <= w else abs(a-b)-w)