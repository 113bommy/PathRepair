n=int(input())
p=int(input())
i=0
d=n
while n<p:
    n=n*d
    i+=1
if(n==p):
    print('YES\n',i,sep='')
else:
    print('NO')
