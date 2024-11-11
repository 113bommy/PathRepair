sum=int(input())
b=input()
l=[]
count=0
for letter in b:
    l.append(int(letter))
    count+=int(letter)
l=sorted(l)
a=2
#print(l)
#print(count)
#print(sum-count)
a=1
count2=0
count3=0
if (count-sum)>=0:
    print(0)
else:
    for el in l:
        if count2<=(sum-count) and el!=9:
            count2+=(9-el)
            count3+=1
    print(count3)