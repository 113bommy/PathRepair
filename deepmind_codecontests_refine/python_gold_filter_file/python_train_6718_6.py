# =^.^= ^^
# kitten
f,v,T=map(int,input().split())
a=list()
for i in range(f):
    t=input()
    a.append(t)
b=0
for i in range(v):
    c=0
    for j in range(f):
        if(a[j][i]=='Y'):
            c+=1
    if(c>=T):
        b+=1
print(b)
