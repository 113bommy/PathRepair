w,h,n=map(int,input().split())
w_d=0
h_d=0
for i in range(n):
  x,y,a=map(int,input().split())
  if a==0:
    w_d=max(w_d,x)
  if a==1:
    w=min(w,x)
  if a==2:
    h_d=max(h_d,y)
  if a==3:
    h=min(h,y)
if w<=w_d or h<=h_d:
  print(0)
else:
  print((w-w_d)*(h-h_d))