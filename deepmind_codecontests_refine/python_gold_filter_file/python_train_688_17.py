n=int(input())
str=""
li=[0,1]
for i in range(2,1001):
     li.append(li[i-1]+li[i-2])
for i in range(1,n+1):
    if i in li:
        str+='O'
    else:
        str+='o'
print(str)
