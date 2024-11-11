lista=input().split(' ')
def prueba(f,*params):
    i=1
    for a in params:
        if f(a[0],a[1])!=a[2]:
             print("El caso",i,"es incorrecto se respondio",f(a[0],a[1]),"y se esperaba",a[2]) 
        else:
            print("El caso",i,"es correcto")
        i+=1    
def comparacion(f,g,*casos):
    for a in casos:
        print("La primera responde",f(a[0],a[1]),"y la segunda funcion responde",g(a[0],a[1]))
def gcd(a,b):
    if a<b:
        return gcd(b,a)
    if b==0:
        return a    
    resto=a%b
    if resto>b//2:
        return gcd(b,b-resto)
    else:
        return gcd(b,resto)
def Unusual2(x,y):
    a=set()
    M=10**9+7
    if y<=x or y%x!=0:
        return 0
    y//=x            
    for i in range(1,int(pow(y,0.5)+1)):
        if y%i==0:
            a.add(i)
            a.add(y//i) 
    lista=sorted(list(a))
    copia=lista[::]
    for i in range(len(lista)):
        copia[i]=int(pow(2,lista[i]-1))
        for j in range(i):
            if(lista[i]%lista[j]==0):
                copia[i]-=copia[j]
    return copia[len(copia)-1]%M                       
print(Unusual2(int(lista[0]),int(lista[1])))

