x,y=map(int,input().split())
x=0 if x>=4 else x
y=0 if y>=4 else y
print(1000000 if x==1 and y==1 else (x+y)*100000)