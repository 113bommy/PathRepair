x=int(input())
n=str(x)
y=int(n,2)
c=0
k=0
while (4**k)<=y:
    k+=1
    c+=1
print(c)