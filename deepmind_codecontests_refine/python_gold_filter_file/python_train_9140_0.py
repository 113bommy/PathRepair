n=int(input())
p=list( float(s) for s in input().split() )
 
res=[1-p[0], p[0]]+[0]*(n//2 - 1)
for i in range(1,n):
    for j in range(len(res)-1, 0, -1):
        res[j]=(res[j]*(1-p[i]) + (res[j-1]*p[i]) )
    res[0]=res[0]*(1-p[i])
print( (1-sum(res[:1+n//2])) )