n,k=map(int, input().split())
a=[list(map(int, input().split())) for i in range(n)]
a.sort()
#print(a)
b=[]
c=0
for i,j in a:
    k-=j
    c=i
    if k<0: break
print(c)