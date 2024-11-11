a,x,y,d,e=map(int,input().split())
k=  input()
m=0
for i in k:
    m +=1
    if  (i=='S')and (y>e):
        y-=1
    elif (i=='E') and (x<d):
        x+=1
    elif (i=='N') and (y<e):
        y+=1
    elif  (i=='W') and (x>d):
         x-=1
    if y==e and x==d:
        print(m)
        break
if y!=e or  x!=d:
    print(-1)
