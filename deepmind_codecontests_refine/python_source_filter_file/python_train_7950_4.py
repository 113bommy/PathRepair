from math import ceil ,floor 
x,y,n=map(int,input().split())
if 1==2:
    print('djgisf')
else: 
    p=x/y 
    now=[]
    mini=10**9  
    a=y-n 
    for req in range(0,y+1,1):
        up=req*(x/y)
        x1=x-up 
        y1=y-req 
       # print(y1)
        if y1<=0 or y1>n:
            now.append([-1,-1,10**10])
            continue 
        a1=x1/y1 
        a2=floor(x1)/y1 
        a3=ceil(x1)/y1
      #  print(p,a1,a2,req)
        if abs(a2-p)<=abs(a3-p):
            now.append([floor(x1),y1,round(abs(a2-p),12)])
        else: 
            now.append([ceil(x1),y1,round(abs(a3-p),12)])
    now=now[::-1]
    for i in range(len(now)): 
        diff=now[i][2]
        if diff<mini: 
            mini=diff 
            a=now[i][0]
            b=now[i][1]
    #print(now)
    print(str(a)+'/'+str(b))