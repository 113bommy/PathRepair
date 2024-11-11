num=int(input())
li=[]
for i in range(1,512) :
    li.append(int((bin(i)).replace("0b","")) )
count=0
for i in li :
    if i<=num :
        count+=1
print(count)