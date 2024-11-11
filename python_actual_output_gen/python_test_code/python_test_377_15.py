m=int(input())
for i in range(m):
    a,b=input().split(' ')
    c=list(map(int,input().split(' ' )))
    d=sorted(c)
    e=0
    for k in range(1,int(a)):
        e+=(int(b)-d[i])//d[0]
    print(e)

