n,t=map(int,input().split())
li=[int(x) for x in input().split()]
k=1
ll=[]
while k<n:
    k=k+li[k-1]
    ll.append(k)
if t in ll:
    print('YES')
else:
    print('NO')
