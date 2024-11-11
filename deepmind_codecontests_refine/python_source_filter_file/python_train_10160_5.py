n,m,k,t=map(int,input().split())
arr=[]
for i in range(k):
    g,h=map(int,input().split())
    arr.append([g,h])
arr.sort()
for i in range(t):
    g,h=map(int,input().split())
    re=0
    bl=True
    for i in arr:
        if(i[0]==g and i[1]==h):
            bl=False
            break
        if((i[0]==g and i[1]<h) or (i[0]<g)):
            re+=1           
    # print("Count is",re,"for",g,h)  
    if(bl):
        
        tm=(g-1)*m+(h-1)
        re=tm-re
        # print("fruitfull are",tm)
        
        if(re%3==0):
            print("Carrots")
        elif(re%3==1):
            print("Kiwi")
        else:
            print("Grapes")
    else:
        print("Waste")