n,m=map(int,input().split())
l=[]
for i in range(n):
    k=list(map(int,input().split()))[1:]
    l+=k
l=list(set(l))
if len(l)==m:
    print('YES')
else:
    print('NO')   