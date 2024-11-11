a=int(input())
b=[]
c=[]
for i in range(a):
    b.append(int(input()))
c=list(set(b))
d=[0 for i in range(len(c))]
for i in range(len(c)):
    for j in range(len(b)):
        if c[i]==b[j]:
            d[i] +=1
n=0
e=[]
for i in range(len(c)):
    for j in range(len(c)):
        if i==j:
            continue
        if d[i]==d[j]:
            e.append((c[i],c[j]))
            n+=1

f=list(set(e))            
if  n==2 and d[0]==d[-1]:
    print("YES")
    for i in range(int(len(f)/2)):
        print(f[i][0],f[i][1])
else :
    print("NO")
####################  