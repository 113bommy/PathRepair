def Find(i,x):
    for z in range(i,len(S)):
        if(S[z]==x):
            return z
    return False

            


n=int(input())

L=[]

for i in range(n):
    s=input()
    L.append(s)

S=input()
ind=0
case=True

Y="<3"

for item in L:
    Y+=item
    Y+="<3"
ind=0
case=True
for item in Y:
    x=Find(ind,item)
    if(type(x)==bool):
        case=False
        break
    ind=x+1
if(case):
    print("yes")
else:
    print("no")



    
    
