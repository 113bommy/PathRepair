n=int(input())
P=[]
for i in range(n):
    x,y=map(int,input().split())
    P.append((x,y))
print(P)
ans=0
for i in range(n):
    a=False
    b=False
    c=False
    d=False
    for j in range(n):
        if(i==j):
            continue
        if(P[j][0]>P[i][0] and P[j][1]==P[i][1]):
            a=True
        if(P[j][0]<P[i][0] and P[j][1]==P[i][1]):
            b=True
        if(P[j][0]==P[i][0] and P[j][1]>P[i][1]):
            c=True
        if(P[j][0]==P[i][0] and P[j][1]<P[i][1]):
            d=True
    if(a and b and c and d):
        ans+=1
print(ans)
