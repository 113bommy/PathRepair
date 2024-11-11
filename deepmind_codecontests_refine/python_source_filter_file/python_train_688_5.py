n=int(input())
a=0
b=1
aa=[]
aa.append(a)
aa.append(b)
for i in range(3,n+1):
    c=a+b
    aa.append(c)
    a=b
    b=c
s=""
for i in range(n):
    if((i+1) in aa):
        s+="O"
    else:
        s+="o"
print(s)