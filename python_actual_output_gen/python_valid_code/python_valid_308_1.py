a,b= input().split()
li=[]

test=[]
for i in range(int(a)):
    x,y= input().split()
    for i in range(int(x), int(y)+1):
        test.append(i)

for i in range(1, int(b)):
    if i not in test:
        li.append(i)

print(len(li))
for i in li:
    print(i, end=" ")