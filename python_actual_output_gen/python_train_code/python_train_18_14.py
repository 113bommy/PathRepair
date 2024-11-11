n,m=map(int,input().split())
l=[]
for i in range(n):
    k=list(map(int,input().split()))
    l+=k
p=list(set(l))
if len(p)==m:
    print('YES')
else:
    print('NO')