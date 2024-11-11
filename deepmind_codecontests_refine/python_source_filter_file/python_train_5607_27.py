x,y = map(int,input().split())

a = y-x if y-x >= 0 else float("inf")
b = y+x+1 if y+x >= 0 else float("inf")
c = x-y+2 if x-y >=0 else float('inf')
d = -(y+x)+2 if x+y <=0 else float('inf')

print(min(a,b,c))

