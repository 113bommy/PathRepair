n=int(input())
x,y,h=[0]*n,[0]*n,[0]*n
for i in range(n):
  x[i],y[i],h[i]=map(int,input().split())
mn_h=min(h)
mx_h=max(h)
for C_x in range(101):
  for C_y in range(101):
    for i in range(n):
      H=h[i]+abs(x[i]-C_x)-abs(y[i]-C_y)
      if H>0:
        if all(max(H-abs(x[j]-C_x)-abs(y[j]-C_y),0)==h[j] for j in range(n)):
          print(C_x,C_y,H)
          exit()