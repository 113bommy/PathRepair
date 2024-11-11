N=int(input())
points=[]
ds=[]
for i in range(N):
  x,y,d=input().split()
  x,y=map(int,(x,y))
  if d=='L':d=(-1,0)
  if d=='R':d=(1,0)
  if d=='U':d=(0,1)
  if d=='D':d=(0,-1)
  points.append((x,y))
  ds.append(d)

if N==1:
  print(0)
  exit()

x,y=list(zip(*points))
xmax,xmin,ymax,ymin=max(x),min(x),max(y),min(y)

def region(p):
  x,y=list(zip(*p))
  return (max(x)-min(x))*(max(y)-min(y))

def process(p,d,second=1):
  return [(p[i][0]+second*d[i][0],p[i][1]+second*d[i][1]) for i in range(N)]

def func(x):
  return region(process(points,ds,x))

def ternary_search(f, x_min, x_max, epsilon=1e-15):
    while True:
        x1,x2 = 1/3*(x_max-x_min)+x_min,2/3*(x_max-x_min)+x_min
        gap = f(x1)-f(x2)
        if gap < 0: x_max=x2
        else: x_min=x1
        if abs(gap) <= epsilon:break
    return (x_max+x_min)/2
  
t_max=4*(max(xmax-xmin,ymax-ymin))
t_min=0

x_opt = ternary_search(func, t_min, t_max, epsilon=1e-15)

print(func(x_opt))