x = [int(i) for i in list(input().split(" "))]
x.append(0)
t = 0
i=0
while(i<4):
    j=i+1
    while(j<4):
        if x[i]==x[j]:
            t+=1
        j+=1
    i+=1
if (t==0 or t==1):
    print(t)
elif (t==3 or t==2):
    print(2)
else:
    print(3)