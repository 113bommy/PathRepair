W,H,x,y=map(int, input().split())
if x==W//2 and y==H//2:
    a=1
else:
    a=0
print(W*H/2,a)