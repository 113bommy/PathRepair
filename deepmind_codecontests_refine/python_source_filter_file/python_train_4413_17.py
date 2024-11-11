n=int(input())
s=''
x=0
d={}
z=0
s=[]
n1=list(map(int,input().split()))
n2=list(map(int,input().split()))
for i in range(1,n+1):
    s.append(str(i))
for f in range(1,n+1):
    s.append(str(i))
    
m=0
for j in range(n):
    d[j+1]=n1[j]
w=s[s.index(str(n2[0])):]
for k in w:
    if(k==str(n2[1])):
        break
    else:
        z=z+d[int(k)]
n2.reverse()
b=s[s.index(str(n2[0])):]
for c in b:
    if(c==str(n2[1])):
        break
    else:
        x=x+d[int(c)]
print(min(x,z))
    
