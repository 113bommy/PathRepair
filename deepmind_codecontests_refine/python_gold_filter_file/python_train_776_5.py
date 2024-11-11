a=input()
a=list(a)
for i in range(len(a)):
    a[i]=int(a[i])
#print(a)
ans=max(a)
print(ans)
for j in range(ans):
    aa=[0]*len(a)
    for i in range(len(a)):
    
        if a[i]!=0:
            aa[i]=1
            a[i]-=1
   
        
    print(int(''.join(str(x) for x in aa)),end=" ")