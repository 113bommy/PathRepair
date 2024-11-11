barra=input()
x=0
izq=0
der=0
for k in range(0,len(barra)):
    if(barra[k]=='^'):
        pp=k
for k in range(0,pp):
    if(barra[k]!='='):
        izq+=int(barra[k])*(pp-k)
for k in range(pp+1,len(barra)):
    if(barra[k]!='='):
        der+=int(barra[k])*(pp-k)
if(izq+der>0):
    print("left")
else:
    if(izq+der==0):
        print("balance")
    else:
        print("right")

        
        
 