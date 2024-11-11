n=int(input())
t=[int(x) for x in input().split()]
a=b=c=0
for i in range(n):
    if t[i]==1:
        a+=1
    elif t[i]==2:
        b+=1
    else:
        c+=1
w=min(a,b,c)
print(w)
if w!=0:
    for i in range(1,w+1):
        q=t.index(1)
        t[q]==0
        w=t.index(2)
        t[w]==0
        e=t.index(3)
        t[e]==0
        print(str(q+1)+" "+str(w+1)+" "+str(e+1))
