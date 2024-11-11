n,p,k=[int(i) for i in input().split()]
l=['('+str(p)+')']
for i in range(p+1,min(p+k+1,n+1)):
    l.append(i)
for i in range(p-1,max(0,p-k-1),-1):
    l=[i]+l
if(p>1):
    l=['<<']+l
if(p<n):
    l.append('>>')
for i in l:
    print(i,'',end='')
