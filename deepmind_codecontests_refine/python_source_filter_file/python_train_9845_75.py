n=int(input())
x=str(input())
v=int(len(x))
b=0;g=0
if (v!=n):
    print("u must enter the right num")
else :
    for i in range(v):
        if x[i]=="A":
            b+=1
        elif x[i]=="D":
            g+=1
if (b>g):
    print("Anton")
elif (g>b):
    print("danik")
else:
    print("friend ship")