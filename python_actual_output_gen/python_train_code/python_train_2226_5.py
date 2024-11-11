n,m=map(int, input().split())
x=set()
y=set()
for i in range(m):
    a,b=map(int, input().split())
    if a==1:x.add(b)
    if b==n:y.add(a)
if x&y:print('POSSIBLE')
else:print('IMPOSSILE')