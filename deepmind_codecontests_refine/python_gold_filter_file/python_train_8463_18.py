n,m=map(int,input().split())
t="."*m
last,first=n+1,-1
L,R=m,-1
a=[]
for i in range(n):
    s=input()
    a.append(s)
    if s!=t:
        last=i;
        if first==-1:
            first=i
    L1=s.find("*")
    R1=s.rfind("*")
    if L1>=0:
        if L>L1:L=L1
    if R1>=0:
        if R<R1:R=R1

for i in range(n):
    if i>=first and i<=last:
        print(a[i][L:R+1])
        
    
    
