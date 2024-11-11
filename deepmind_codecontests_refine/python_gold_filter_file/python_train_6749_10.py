n=int(input())
a=[]
for i in range(n):
    a.append(list(map(int,input().split())))
b=[]
for i in range(n):
    b.append(list(map(int,input().split())))
b.sort()
a=sorted(a,key=lambda x: -x[1])
ans=0
vb=[]
for i in range(n):
    for j in range(n):
        if not j in vb:
            if a[i][0]<b[j][0] and a[i][1]<b[j][1]:
                vb.append(j)
                ans+=1
                break
print(ans)
