n=int(input())
i=list(input())
x=0
y=0
cost=0
for index in range(len(i)-1):
    if(i[index]=='U'):
        y+=1
    elif(i[index]=='R'):
        x+=1
    if(x==y):
        if((i[index]=='U' and i[index+1]=='U') or (i[index]=='R' and i[index+1]=='R')):
            cost+=1
print(cost)