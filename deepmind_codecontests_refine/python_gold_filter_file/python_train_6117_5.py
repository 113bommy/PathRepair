nm=list(map(int,input().split()))
n=nm[0]
m=nm[1]
q=list(map(int,input().split()))
p=list(map(int,input().split()))
l=[]
for i in p:
    if(i in q):
        l.append(q.index(i))
l.sort()
for k in l:
    print(q[k],end=' ')