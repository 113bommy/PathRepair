t=int(input())

while 1:
   
    t=str(t)
    y=list(t)
    x=list(map(int,y))
    p=sum(x)
    if p%4==0:
        z="".join(map(str,x))
        print(z)
        break
    t=int(t)+1
    
