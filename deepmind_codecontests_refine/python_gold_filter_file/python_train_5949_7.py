n,m,k=map(int,input().split())
l=list(map(int,input().split()))
a=n//k
su=0
li=(a-1)*k
for i in range(n):
    l[i]=(i+1,l[i])
    
l.sort(reverse=True,key=lambda x:x[1])
lol=m*k
#print(lol,l)
for i in range(lol):
    su=su+l[i][1]
#print(l)
l=l[:m*k]
#print(l)
print(su)
kk=0
l.sort()
for i in range(m, m * k, m):
    print(l[i][0]-1,end=" ")
print()