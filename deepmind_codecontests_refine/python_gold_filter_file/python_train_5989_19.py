n=int(input())


cnt=0

x=[]
for i in range(n):
    x.append(0)

for i in range (n):
    l=list(input())
    g=l.count('C')
#   print(g)
    if(g>1):
        cnt+=g*(g-1)/2

    for j in range (n):
        if(l[j]=='C'):
            x[j]+=1

#print(x)
for j in range (n):
    if (x[j] > 1):
       cnt+=x[j]*(x[j]-1)/2

print(int(cnt))
