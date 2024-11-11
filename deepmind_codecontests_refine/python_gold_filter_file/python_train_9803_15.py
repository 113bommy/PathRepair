def gns():
    return [int(x) for x in input().split()]
n=int(input())
ns=[None]*(n+1)
def sift(x,cl):
    i=x
    while i<=n:
        ns[i]=cl
        i+=x
i=2
cl=1
while i<=n:
    while i<=n and ns[i]!=None:
        i+=1
    if i>n:
        break
    sift(i,cl)
    i+=1
    cl+=1
for i in range(2,n):
    print(ns[i],end=' ')
print(ns[-1])
