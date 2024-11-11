x,y,m=[int(i) for i in input().split(' ')]
x,y=max(x,y), min(x,y)
a=0
if x>=m:print(0); quit()
if x<=0 and x<=0: print(-1); quit()
if x+y<0: a=abs(y/x)+1; y+=a*x
while max(x,y)<m:
    if x<y:
        x+=y
    else:
        y+=x
    a+=1
print(int(a))
    
