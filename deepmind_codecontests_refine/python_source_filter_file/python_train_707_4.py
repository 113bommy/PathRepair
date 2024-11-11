def SUNUKE(i):
    x=str(i)
    SUM=0

    for j in range(len(x)):
        SUM+=int(x[j])

    return SUM,i/SUM

SUNUKESUU=[0,1,2,3,4,5,6,7,8,9]
i=10
keta=0

while i<10**5:


    if SUNUKE(i)[1]>=10**keta:
        i-=10**keta
        keta+=1
        
    else:
        if SUNUKESUU[-1]!=i:
            SUNUKESUU+=[i]
        i+=10**keta
    

for i in range(1,int(input())+1):
    print(SUNUKESUU[i])
