n,m=input().split()
c=int(m)
d=int(n)
b=[]
i=0
h=0
k=map(int,input().split())
f=list(k)
##print(f)
f.sort()
##print(f)
while i<d:
    if f[i]<=0:
        b.append(f[i])
    else:
        pass
    i+=1
print(b)
j=0
l=len(b)
if l<c:
    while j<l:
        y=b[j]
        h=h+y
        j=j+1
elif l>=c:
     while j<c:
        y=b[j]
        h=h+y
        j=j+1
print(h*-1)    
  
    
