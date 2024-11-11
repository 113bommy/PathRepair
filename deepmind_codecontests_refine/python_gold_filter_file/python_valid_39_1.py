test=int(input())
while test:
    test-=1
    width,height=map(int,input().split())
    x1,y1,x2,y2=map(int,input().split())
    sw,sh=map(int,input().split())
    
    lowerv=y1
    lowerh=x1
    topv=height-y2
    toph=width-x2
    
    h1,h2=10**11,10**11
    flag=0
    if lowerv+topv>=sh:
            flag=1
            if sh<=max(lowerv,topv):
                h1=0
                
            else:
                h1=sh-max(lowerv,topv)
                
    if lowerh+toph>=sw:
            flag=1
            if sw<=max(lowerh,toph):
                h2=0
                
            else:
                h2=sw-max(lowerh,toph)
        
        
    if flag:        
        print(min(h1,h2))
                
        
    else:
        print(-1)