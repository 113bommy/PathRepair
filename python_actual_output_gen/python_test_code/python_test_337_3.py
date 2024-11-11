k=int(input())
s=input()
d={}
res=0
x=0
for i in s:
    if i=='1':
        x+=1
    res=d.get(x-k,0)
    d[x]=d.get(x,0)+1
print(res)