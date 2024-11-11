n=int(input())
vec=list(map(int,input().split()))
al=[]
otrez=[]
for x in vec:
    if len(al)==0:
        al.append(x)
    elif(x<=al[-1]):
        otrez.append(al)
        al=[x]
    else:
        al.append(x)
otrez.append(al)
maxx=0
if(len(otrez)!=1):
    for i in range(0,len(otrez)-1):
        if(len(otrez[i])==1)or(len(otrez[i+1])==1):
            maxot=len(otrez[i])+len(otrez[i+1])
        elif (otrez[i+1][0]-otrez[i][-2])>1 or (otrez[i+1][1]-otrez[i][-1])>1:
            maxot=len(otrez[i])+len(otrez[i+1])
        else:
            maxot=max([len(otrez[i]),len(otrez[i+1])])
        if(maxot>maxx):
            maxx=maxot
    print(maxx)
else:
    print(len(otrez[0]))