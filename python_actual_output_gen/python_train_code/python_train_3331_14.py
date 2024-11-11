n=input().split()
list=[int(x) for x in input().split()]
max=0
counter = 0
for i in range (len(list)-1) :
    if list[i]>=max :
        max=list[i]
if max ==0 :
    print (0)
else:
    counter=counter+1
    while max != 0 :
        max = max - 1
        if max in list and max !=0 :
            counter = counter+1
    print (counter)