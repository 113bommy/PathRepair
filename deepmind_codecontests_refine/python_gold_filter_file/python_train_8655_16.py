z=str(input())

count=0
counti=0
status=False
for i in range(len(z)) :
    if z[i]=="a" :
        count+=1
    else :
        counti+=1
        status=True
if status :
    if counti>=count :
        print(count+count-1)
    else :
        print(count+counti)
else :
    print(count)