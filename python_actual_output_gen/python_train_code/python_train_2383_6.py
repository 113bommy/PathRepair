n=int(input())
p=int(input())
i=0
while n<p:
    n=n*n
    i+=1
if(n==p):
    print('YES\n',i,sep='')
else:
    print('NO')