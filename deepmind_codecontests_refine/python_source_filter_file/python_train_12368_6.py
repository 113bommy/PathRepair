w,h,x,y=map(int,input().split())
a = 0
if(h==2*x and w ==2*y):
  a +=1
print(w*h/2,a)
