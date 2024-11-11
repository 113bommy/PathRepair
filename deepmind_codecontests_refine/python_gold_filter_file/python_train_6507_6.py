import math
k=[]
v=[]
while(1):
    try:
        s=input()
        k+=[len(s)]
        v+=[s]
    except EOFError:
        break
ma=max(k)
print((ma+2)*"*")
c=0
for i in range(len(k)):
    val=ma-k[i]
    if val%2==1:
        c+=1
    if c%2==0:
        o=math.ceil(val/2)
        s=val-o
    else:
        o=val//2
        s=val-o
    if i!=len(k)-1:
        print("*"," "*o,v[i]," "*s,"*",sep="")
    elif i==len(k)-1:
        print("*", " " * o, v[i], " " * s, "*", sep="")
        print((ma+2)*"*")