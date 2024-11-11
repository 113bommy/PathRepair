p=input()
p=p.split()
n=int(p[0])
t=int(p[1])
m=int('1'+(n-1)*'0')
q=int(n*'9')
c=0
e=0
for i in range(m,q):
    if i%t==0:
        c=1
        e=i
        break
if c==1:
    print(e)
else:
    print(-1)
