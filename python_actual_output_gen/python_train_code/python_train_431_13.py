import sys
import math

n,A,B=map(int,input().split())
s=[int(x) for x in input().strip().split()]
sorta=s[1:]
sorta=sorted(sorta, reverse=True)
cota=0
print(sorta)
print(s)
suma=sum(sorta)
if(B==0 or n==0):
    print(cota)
elif(math.floor((s[0]*A)/sum(s))>=B):
    print(cota)

else:
    for i in range(0,n):
        suma-=sorta[i]
        cota+=1
        if(math.floor(s[0]*A/suma)>=B):
            print(cota)
            break

