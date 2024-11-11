w, h, x, y, r=map(int,input().split())
if x-r=>0 and r+x=<w and y-r>0 and r+y<h:
    print("Yes")
else:
    print("No")