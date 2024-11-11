x,y=map(int,input().split())
z,k,l=[],[],[]
j,b,c=0,0,y
s=set()
for i in range(x):
    a=list(map(int,input()))
    z.append(a)
while c:    
    j=0
    k=[]
    for i in z:
        k.append(i[b])
        j+=1
        if(j==x):
            l.append(k)
            b+=1
    c-=1  
for i in l:
    a=1
    for j in i:
        if(max(i)==j):
            s.add(a)
            a+=1
print(len(s))