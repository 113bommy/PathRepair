out=[]
n,p,k=map(int,input().split())

left=p-k
right=p+k
closed=True
if left>1:
    print('<< ',end='')
else:
    left=1

if right>n:
    closed=False
    right=n
for i in range(left,right+1):
    if i==p:
        print('(',i,') ',sep='',end='')
    else:
        print(i,end=' ')
if closed:
    print('>>')
