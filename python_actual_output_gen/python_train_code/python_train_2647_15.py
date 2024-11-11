x=int(input())
q=[]
for i in range(x):
    a=int(input())
    b=list(input().split())
    for j in range(a):
        b[j]=int(b[j])
    b.sort()
    c=1
    t=1
    for f in range(a-1,-1,-1):
        if(c>b[f]):
            t=c-1
            print(b)
            break
        if(c==a):
            t=a
        c=c+1
    if(t<1):
        t=1
    
    q.append(t)
for k in range(len(q)):
    print(q[k])
