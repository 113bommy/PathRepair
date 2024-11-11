while(1):
    try:
        a=[0,0,0]
        a[0],a[1],a[2]=map(int,input().split())
        b=sorted(a)
        c=sum(b[:2])
        d=(c-b[2])//2
        if b[2]>c or c-b[2]==1:
            print("Impossible")
        else:
            ind=a.index(b[2])+1
            if ind==1:
                print(a[1]-d,d,b[2]-(a[1]-d))
            elif ind==2:
                print(a[0]-d,b[2]-(a[0]-d),d)
            else:
                print(d,a[1]-d,b[2]-(a[1]-d))
    except EOFError:
        break
                

                
            
                    