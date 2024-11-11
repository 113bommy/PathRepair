l=[int(i) for i in input().split()]
o=[]
m=sum(l)%2
if m!=0:
    print("NO")
else:
    h=int(sum(l)/2)
    for i in range(6):
        for j in range(i,6):
            for t in range(j,6):
                k=l[i]+l[j]+l[t]
                o.append(abs(k-h))
    if min(o)==0:
        print("YES")
    else:
        print("NO")