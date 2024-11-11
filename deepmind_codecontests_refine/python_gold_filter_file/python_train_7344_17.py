n,a,b=map(int,input().split())
l=list(map(int,input().split()))
m=[]
c=0
s=0
for i in l:
    if i<=a:
        m.append(i)
for i in m:
    s=s+i
    if(s>b):
        c+=1
        s=0
print(c)