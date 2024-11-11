s=input()
n=int(input())
l=[]
for i in range(n):
    d=input()
    if(d.find(s)==0):
        l.append(d)
if(len(l)>0):
    m=l[0]
    for i in range(1,len(l)):
        if(l[i]<m):
            m=l[i]
    print(m)
else:
    print(s)
