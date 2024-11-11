s=input().rstrip()
x=list(s)
if len(x)%2==0:
    t=(len(x)//2)-1;
    p=x[0:t]
    q=x[t+2:len(x)]
    l=[]
    for j in range(t,t+2):
        l.append(x[j])
    a=len(p)-1
    for i in range(0,len(p)):
        l.append(p[a-i])
        l.append(q[i])
    C=''.join(l)
    print(C)
else:
    t=(len(x)//2);
    p=x[0:t]
    q=x[t+1:len(x)]
    l=[]
    l.append(x[t])
    a=len(p)-1
    for i in range(0,len(p)):
        l.append(q[0])
        l.append(p[a-i])
    C=''.join(l)
    print(C)    
