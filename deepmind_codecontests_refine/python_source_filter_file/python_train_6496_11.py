a,b=map(int,input().split())
if b==1:
    print(b)
else:
    c=list(map(int,input().split()))
    l=[(i,z) for i,z in zip(c,c[1:])]
    total=l[0][0]-1
    for i in l:
        if i[1]>=i[0]:
            total+=i[1]-i[0]
        else:
            total+=(a-i[0])+i[1]
    print(total)  