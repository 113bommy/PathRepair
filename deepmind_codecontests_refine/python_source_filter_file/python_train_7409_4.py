x=input()
x=x.split()
arreglo=input()
arreglo=arreglo.split()
suma=0
contador=0
k=-1
for a in range (1,int(x[0])):
        if int(arreglo[1])==int(arreglo[a]):
                contador=contador+1
if contador==(int(x[0])-1) and int(x[0])>2:
        suma=(contador*(contador+1))//2
else:
        for p in range (1,len(arreglo)):
                k=k+1
                if int(arreglo[k])>=int(arreglo[p]):
                        u=int(arreglo[k])-int(arreglo[p])
                        s=(u//int(x[1]))+1
                        arreglo[p]=int(arreglo[p])+(int(x[1])*s)
                        suma=suma+s
                        
print(suma)