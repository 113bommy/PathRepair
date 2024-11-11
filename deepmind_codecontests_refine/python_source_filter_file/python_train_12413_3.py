t=int(input())
while(t!=0):
    a=int(input())
    b=list(map(int,input().split(" ")))
    c=set(b)
    c=list(c)
    e=[]
    count=0
    w=0
    if(a==1):
        print(0)
    else:
        b.sort()
        for i in range(0,a-1):
            if(b[i]==b[i+1]):
                count=count+1
                w=1
                if(i==a-2):
                    e.append(count+1)
            elif(w==1):
                count=count+1
                e.append(count)
                count=0
                w=0
        if(len(e)==0):
            print(1)
        else:
            f=max(e)
            g=len(c)
            if(f==g):
                print(f-1)
            elif(f<(g-1)):
                print(f)
            else:
                print(g-1)
    t=t-1
        
        