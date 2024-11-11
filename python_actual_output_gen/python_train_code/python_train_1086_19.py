a=input()
b=input()   
i=len(a)-1
j=len(b)-1
c=0
if i<0 or j<0:
    print(i+j+2)
else:
    while i>0 and j>0 and a[i]==b[j]:
        c+=1
        i-=1
        j-=1
    print(i+j+2)
