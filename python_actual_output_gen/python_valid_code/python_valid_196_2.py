n,k=map(int,input().split())
r=2
g=5
b=8
r1=r*n
g1=g*n
b1=b*n
c=0
if(r1%2==0):
    p=r1//k
else:
    p=(r1//k)+1
    
if(g1%5==0):
    q=g1//k
else:
    q=(g1//k)+1
    
if(b1%8==0):
    r=b1//k
else:
    r=(b1//k)+1

print(p+q+r+1)
    
    
