d={"A":0,"B":0,"C":0}
for i in range(3):
    x=input()
    a=x[0]
    b=x[1]
    c=x[2]
    if(b==">"):
        d[x[0]]+=1
        d[x[2]]-=1
    else:
        d[x[0]]-=1
        d[x[2]]+=1
l1=list(d.values())
l2=list(d.keys())
#print(d)
l3=[[l1[0],l2[0]],[l1[1],l2[1]],[l1[2],l2[2]]]
l3.sort(key =lambda x:x[0])
if(len(set(l1))!=len(l1)):
    print("IMPOSSIBLE")
else:    
    for i in range(3):
        print(l3[i][1],end="")
    
    
            
