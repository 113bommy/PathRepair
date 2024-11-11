n=int(input())
p=list(map(int,input().split()))
n=max(p)
l=[True]*(1000001)
l[0],l[1]=False,False
if n>=2:
    l[2]=True
    for i in range(2,1000001):
        if l[i]:
            for j in range(i*i,1000001,i):
                l[j]=False

for i in p:
    if pow(i,0.5) * pow(i,0.5)==i and l[int(pow(i,0.5))]:
        print("YES")
    else:
        print("NO")