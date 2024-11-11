n,m=map(int,input().split())
b=0
l=[]
for i in range(n):
    a = list(map(int,input().split()))
    for x in range(1,a[0]+1):
        l.append(a[x])
print (["NO","YES"][len(set(l))==m])   