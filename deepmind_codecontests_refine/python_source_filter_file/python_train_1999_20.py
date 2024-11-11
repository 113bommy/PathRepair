records1 = list(map(int, input().split()))
records = records1[0]
size = records1[1]
li = list(map(int, input().split()))
li2=[]
for i in range(0,len(li)):
    if li[i] in li2:
        continue
    else:
        if(len(li2)>=size):
            li2.pop()
            li2.append(li[i])
        else:
            li2.append(li[i])
print(len(li2))
li3 = li2[::-1]
for i in li3:
    print(i,end=" ")
