z1=[]
for i in range(1,10):
    z="0"*(i-1)+"1"*i
    s=0
    for i in range(len(z)):
        if z[i]=="1":s+=1<<i
    z1+=[s]
a=int(input());i=0;w=0
while(i<1):
    if a%z1[i]==0:w=z1[i]
    i+=1
print(w)

