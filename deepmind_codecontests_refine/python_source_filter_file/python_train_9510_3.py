#205A
n = int(input(""))
l = input("")
o = l.split(" ")
count=0
#########################################

min = int(o[0])

for i in range(1,n):
    c=int(o[i])
    #print(c)
    if min<c:
        pass
    elif min>c:
        min=c

for i in o:
    if int(i)==min:
        count+=1
    else:
        continue


if count>1:
    print("Still Rodzil")
else:
    print(o.index(str(min))+1)
