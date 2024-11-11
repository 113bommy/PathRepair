s=input()
k=int(input())
q={}
for i in s:
    if i in q:
        q[i]+=1
    else:
        q[i]=1
l=[]
w=0
while k-w>0:
    w=min(q.values())
    for i in q:
        if q[i]==w and k-w>0:
            l+=[i]
            q[i]=10**6
            k-=w
for i in l:s=s.replace(i,"")
print(len({*s}))
print(s)