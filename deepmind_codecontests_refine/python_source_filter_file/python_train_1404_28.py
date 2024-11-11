n,k = map(int,input().split())
l = [int(n) for n in input().split()]
for i in range(n):
    l[i]=[int(l[i]),i]
ls=sorted(l)
s=i=c=0
for i in range(n):
    s=s+ls[i][0]
    if s<k:
        c+=1
print(c)
if c> 0:
    for i in range(c):
        print(ls[i][1],end=' ')
