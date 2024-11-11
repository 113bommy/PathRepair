line1=[int(x) for x in input().split()]

kids=0

for i in range(line1[0]):
    
    line2=input().split()
    
    x=int(line2[1])
    
    if line2[0]=="+":
        line1[1]+=x
    else:
        if x < line1[1]:
            line1[1]-=x
        else:
            kids+=1
            
print (line1[1], kids)
    
    