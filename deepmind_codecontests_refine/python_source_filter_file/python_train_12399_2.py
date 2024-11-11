n=int(input())
l=list(map(int,input().split()))
m=list(map(int,input().split()))
l.sort()
m.sort()
a=0
b=0
f=0
while(len(l)>0 and len(m)>0):
    if f%2==0:
        if l[-1]>m[-1]:
            a+=l[-1]
            l.pop()
        else:
            m.pop()
            
                
    else:
        if  m[-1]>l[-1]:
            b+=m[-1]
            m.pop()
        else:
           l.pop()
    f+=1

if len(l)!=0:
    for i in range(len(l)-1,-1,-1):
        if f%2==0:
            a+=l[i]
        f+=1
if len(m)!=0:
    for i in range(len(m)-1,-1):
        if f%2==0:
            b+=m[i]
        f+=1

print(a-b)

        
    
    
    
