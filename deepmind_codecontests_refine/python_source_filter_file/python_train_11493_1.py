s=input()
k=s.split()
n=int(k[0])
m=int(k[1])
t=[]
tab=[]
l=[0]
for i in range(m):
    s=input()
    f=s.split()
    t.append(int(f[0]))
    tab.append(int(f[1]))
p=0
v=[]
for i in range(1,n+1):
    s=set()
    
    for j in range(len(tab)):
        if((tab[j]==i)or(t[j]==i)):
            s.add(tab[j])
            s.add(t[j])
    if(list(s)==[]):
        v.append(i)
    
    
    l.append(list(s))
verif=True
cont=0
h=set()
g=set()
for i in range(1,len(l)):
    if (len(l[i])>3):
        
        verif=False
    elif (len(l[i])==3):
        verif=(set(l[l[i][0]])==set(l[l[i][1]]))and(set(l[l[i][0]])==set(l[l[i][2]]))
        l[i]=sorted(l[i])
        g.add(tuple(l[i]))
    elif(len(l[i])==2):
        verif=(set(l[l[i][0]])==set(l[l[i][1]]))
        cont=cont+1;
        l[i]=sorted(l[i])
        h.add(tuple(l[i]))
    if(verif==False):
        
        break
if(verif==False or((len(v)-len(h))<0)):
    print(-1)
elif(((len(v)-len(h))%3)!=0):
   print(-1)
else:
    g=list(g)
    
    for i in range(len(g)):
        f=list(g[i])
        print(f[0],f[1],f[2])
    h=list(h)
    for i in range(len(h)):
        f=list(h[i])
        print(f[0],f[1],v[i])
    for i in range(len(h),len(v)-2,2):
       print(v[i],v[i+1],v[i+2])
   
        
        

    




             
