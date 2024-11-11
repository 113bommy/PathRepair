a=int(input())
b=[]
for i in range(a):
    b.append(list(map(int,input().split())))
for i in range(a):
    c=b[i][0]*b[i][1]*4
    d=2*(b[i][0]+b[i][1])
    e=c-d
    f=b[i][0]*b[i][1]
    if(f==(e/2)):
        print("YES")
    else:
        print("NO")