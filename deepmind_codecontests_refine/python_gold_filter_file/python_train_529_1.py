
dizi=list(input("").split())

sayi=int(dizi[0]) #1
n=sayi
L=int(  dizi[1]) #3
a=int(dizi[2]) # 2
topla=0
listem=list()
l1=[]
l2=[]
if(n!=0):
    for i in range(n):
        degerler=list(input("").split())
        l1.append(int(degerler[0]))
        l2.append(int(degerler[1]))
start=0
if(n!=0):
    for i in range(n):
        topla+=int((l1[i]-start)/a)
        start=l1[i]+l2[i]
if(n!=0):
    topla+=(L-start)/a
        
if(sayi==0):
    print(int(L/a))
else:
    print(int(topla))