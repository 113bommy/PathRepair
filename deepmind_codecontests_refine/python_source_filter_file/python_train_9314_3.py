n,x,y=map(int,input().split())
M=[list(map(int,input().split())) for i in range(n)]
l=[]
k=0
def evklid(a,b) :
    if a==0 :
        return b
    if b==0 :
        return a
    if a%b==0 :
        return b
    else :
        return evklid(b,a%b)

for i in range(n) :
    x1=M[i][0]-x
    y1=M[i][1]-y
    c=0
    if x1<0 and y1<0 :
        x1=abs(x1)
        y1=abs(y1)
    if x1<0 or y1>0 or x1>0 and y1<0 :
        c=1
        x1=abs(x1)
        y1=abs(y1)
        
    d=evklid(x1,y1)
    x1=x1//d
    y1=y1//d
    if c==1 :
        x1=-x1
    if [x1,y1] not in l :
        k=k+1
        l.append([x1,y1])
print(k)
        
    
    
