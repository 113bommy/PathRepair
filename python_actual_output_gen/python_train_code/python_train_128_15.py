a = int(input())
b = int(input())
if(a>b):
    temp = a
    a = b
    b = temp
temp = i = j = 0
for i in range(b):
    i+=1
    
    a+=1
    if(a==b):
        print(temp+i)
        exit()
    temp+=i
    b-=1
    if(a==b):
        print(temp+i)
        exit()
    temp+=j
print(temp)