n=int(input())
for i in range(n):
    t=int(input())
    l=[]
    q=-1
    p=0;w=0
    if(t%4==0):
        print("YES")
        for j in range(1,t//2+1):
            l.append(j*2)
            p=p+j*2
        for j in range(1,t//2):
            l.append(q+2)
            w=w+q+2
            q=q+2
        l.append(p-q)
        print(*l)
    else:
        print("NO")