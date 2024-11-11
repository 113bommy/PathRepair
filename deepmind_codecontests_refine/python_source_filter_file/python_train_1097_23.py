n=int(input())
sp=[]
w=0
for i in range(n):
    a=list(map(int,input().split()))
    sp.append(a)
for k in range(0,3):
    q=0
    for i in range (n):
        q+=sp[i][k]
    if q==0:
        w+=1
if w==n:
    print ('YES')
else:
    print ('NO')