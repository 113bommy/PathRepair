n,l,t=map(int,input().split())
inf=[]
s=0
for _ in range(n):
x,y=map(int,input().split())
   if y==1:
       x+=t
   else:
       x-=t
    inf.append(x%l)
    s+=x//l
inf.sort()
s%n
for i in range(n):
    print(inf[(i+s)%n])