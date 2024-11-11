a=[]
for i in range(5):
    n=input()
    n=n.split()
    if list(set(n))!=['0']:
        a=n
        w=i+1
for i in range(5):
    a[i]=int(a[i])
    if a[i]==1:
        s=i+1
h=0    
if s==1 or s==5:
    h+=2
if s==2 or s==4:
    h+=1
if w==1 or w==5:
    h+=2
if w==2 or w==4:
    h+=1
print(h)
        
