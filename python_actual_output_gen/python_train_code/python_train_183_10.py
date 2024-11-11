a,b,c,x,y = map(int,input().split())
mo=[a,b]
if(a+b>2*c):
    sum=2*min(x,y)*c+max(x-y,y-x)*min(2*c,mo[x>y],mo[y<x])
else:
    sum=a*x+b*y
print(sum)