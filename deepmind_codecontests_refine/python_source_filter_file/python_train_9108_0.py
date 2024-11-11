n=int(input())
x=[]
for i in range(n):
    a,b=map(int,input().split())
    x.append([a,b])
if n==1:
    print(-1)
elif n==2 and (x[0][0]==x[1][0] or x[0][1]==x[1][1]):
    print(-1)
else:
    if n==2:
        x.append([x[0][0],x[1][1]])
        x.append([x[1][0],x[0][1]])
    elif x==3:
        if x[0][0]!=x[1][0] and x[0][1]!=x[1][1]:
            if [x[0][0],x[1][1]] not in x:
                x.append([x[0][0],x[1][1]])
            else:
                x.append([x[1][0],x[0][1]])
        elif x[0][0]!=x[2][0] and x[0][1]!=x[2][1]:
            if [x[0][0],x[2][1]] not in x:
                x.append([x[0][0],x[2][1]])
            else:
                x.append([x[2][0],x[0][1]])
        else:
            if [x[1][0],x[2][1]] not in x:
                x.append([x[1][0],x[2][1]])
            else:
                x.append([x[2][0],x[1][1]])
    x.sort(key=lambda i:i[0])
    print(abs(x[0][0]-x[2][0])*abs(x[0][1]-x[1][1]))