from math import sqrt 
n,k=input().split(" ")
n,k=int(n),int(k)

x,y=-0.5,-1
a,b=-1,-1

time=0
for i in range(n):
    a,b=input().split(" ")
    a,b=int(a),int(b)
    if x!=-0.5:
        time+=sqrt((x-a)**2+(y-b)**2)/50
    x,y=a,b
print(time)