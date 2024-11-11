n=int(input())
ma=10**10
mi=-10**10
for i in range(n):
    x=input()
    if(x[len(x)-1]=='Y'):
        if(x[0]=='<' and x[1]=='='):
           ma=min(ma,int(x[3:len(x)-2])) 
        elif(x[0]=='<' and x[1]==' '):
            if(int(x[2:len(x)-2])>=0):
                ma=min(ma,int(x[2:len(x)-2])-1)
            else:
                ma=min(ma,int(x[2:len(x)-2])+1)
        elif(x[0]=='>' and x[1]=='='):
            mi=max(mi,int(x[3:len(x)-2]))
        elif(x[0]=='>' and x[1]==' '):
            mi=max(mi,int(x[2:len(x)-2])+1)
    if(x[len(x)-1]=='N'):
        if(x[0]=='<' and x[1]=='='):
            mi=max(mi,int(x[2:len(x)-2])+1)
        elif(x[0]=='<' and x[1]==' '):
            mi=max(mi,int(x[2:len(x)-2]))
        elif(x[0]=='>' and x[1]=='='):
            if(int(x[2:len(x)-2])>=0):
                ma=min(ma,int(x[2:len(x)-2])-1)
            else:
                ma=min(ma,int(x[2:len(x)-2])+1)
        elif(x[0]=='>' and x[1]==' '):
            ma=min(ma,int(x[2:len(x)-2])) 
if(ma<mi):
    print("Impossible")
else:
    print(mi)