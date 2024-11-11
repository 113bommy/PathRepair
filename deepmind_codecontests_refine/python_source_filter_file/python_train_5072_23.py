n,k=map(int,input().split())
l=[int(x) for x in input().split()]
cut=[0 for i in range(n)]
if l[0]&1:cut[0]=-1
else:cut[0]=1
point=[]
for i in range(n-1):
    if l[i]&1:
        cut[i]=cut[i-1]-1
    else:
        cut[i]=cut[i-1]+1
    if cut[i]==0:
        point.append(abs(l[i+1]-l[i]))
point.sort()
cnt=0
while point and k>point[0] :
    cnt+=1
    k-=point[0]
    point=point[1:]
print(cnt)