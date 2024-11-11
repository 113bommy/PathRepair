n=int(input())
l1=['0','4','7']
l2=['4','7']
l3=['4','7']
l=[]
for i in range(0,3):
    for j in range(0,2):
        for k in range(0,2):
            l.append(int(l1[i]+l2[j]+l3[k]))

c=0
l.append(4)
l.append(7)
print(l)
for i in range(0,len(l)):
    if(n%l[i]==0):
        c=c+1
if(c!=0):
    print("YES")
else:
    print("NO")
    
    
    
        
