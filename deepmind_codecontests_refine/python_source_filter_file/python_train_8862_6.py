n=int(input())
a=list(map(int,input().split()))
a.sort()
b={}
for i in range(n):
    b[a[i]]=0
for i in range(n):
    b[a[i]]+=1
c=[]
s=0
for i in b:
    s=0
    for j in range(i,i+6):
        if j in b.keys():
            s=s+b[i]
    c.append(s)
print(max(c))