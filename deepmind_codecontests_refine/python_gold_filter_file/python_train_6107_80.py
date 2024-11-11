x=input()
zc=0
oc=1
for i in x:
    if int(i)==1:
        oc=oc+1
        zc=0
    if int(i)==0:
        zc=zc+1
        oc=0
    if oc>6 or zc>6:
        
        break
    

if oc>6 or zc>6:
    print("YES")        
if oc<7 and zc<7:
    print("NO")