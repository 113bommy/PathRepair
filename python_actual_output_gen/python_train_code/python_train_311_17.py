n,m=map(int,input().split())
s,e=map(int,input().split())
f=True
nxt=e
if s!=0:
    f=False
for i in range(n-1):
    s,e=map(int,input().split())
    if s<=nxt:
        nxt=e
    else:
        f=False

print('YES' if (f and m<=nxt) else 'NO')
    
        