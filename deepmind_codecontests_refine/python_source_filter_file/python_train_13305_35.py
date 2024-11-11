x,y=map(int,input().split())
print([y-x,x+y][y//x == 0] )