x,y = map(int,input().split())
print(min(abs(y-x),abs(x+y)+1))