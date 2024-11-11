n=int(input())
m=input()
a=[]
r,b,g=0,0,0
for i in m:
    if(i=="R"):
        r=r+1 
        b=0
        g=0
        if(r>1):
            a.append(r)
    elif(i=="B"):
        b=b+1 
        r=0
        g=0
        if(b>1):
            a.append(b)
    else:
        g=g+1 
        r=0
        b=0
        if(g>1):
            a.append(g)
print(len(a))
    
