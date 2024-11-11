a=int(input())
b=input()
b=b.split(' ')
c=[]
for i in b:
    c.append(int(i))
s=0
for i in range(1,len(c)-1):
    if c[i]==0 and c[i-1]==1 and c[i+1]==1:
        c[i+1]=0
        s=s+1
print(s)