cash=input()
bills=0
x1=int(cash[len(cash)-1])
while x1!=0:
    if x1>=5:
        x1-=5
        bills+=1
    elif x1>=1:
        x1-=1
        bills+=1
x2=int(cash[len(cash)-2]+'0')
while x2!=0 and len(cash)-2>0:
    if x2>=20:
        x2-=20
        bills+=1
    elif x2>=10:
        x2-=10
        bills+=1
x3=int(cash[:len(cash)-2]+'00')
bills+=x3//100
        
    

print(bills)        