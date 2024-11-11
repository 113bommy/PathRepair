import sys
n=int(input())
l=list(str(input()))
se=set(l)
#print(se)
if(se=={'4'} or se=={'7'} or se=={'4','7'} or se=={'7','4'}):
    pass
    
else:
    print("NO")
    sys.exit(0)
k=int(n/2)
f,e=0,0
for i in range(k):
    f+=int(l[i])
for i in range(k,n):
    e+=int(l[i])
#print(f,e)
if(f==e):
    print('YES')
else:
    print('NO')
