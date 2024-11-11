rows,cols=map(int,input().split())
if rows==1 and cols==1:
    print(0)
elif rows==1:
    q=[]
    for i in range(cols):
        q.append(i+2)
    print(*q)
elif cols==1:
    for i in range(rows):
        print(i+1)  
else:
    q=[]
    for i in range(cols):
        q.append(i+2)
    print(*q)
    for i in range(1,rows):
        a=q[-1]+i
        p=[]
        for j in range(cols):
            p.append(a*q[j])
        print(*p)
        