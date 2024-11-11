import math
guests=input().split()
utensil=input().split()
notstolen=[]
max=0
stolen=0
while utensil!=[]:
    counter=0
    skp=0
    y=utensil[0]
    for i in range (len(utensil)):
        if utensil[0+skp]==y:
            counter+=1
            utensil.pop(0+skp)
        else:
            skp+=1
    notstolen.append(counter)
    if counter>max:
        max=counter
test1=(int(guests[1]))
test2=(math.ceil(max/(int(guests[1]))))
test=test1*test2
print(test1)
print(test2)
print(notstolen)
for i in notstolen:
    stolen+=int(test)-i
print(stolen)