from operator import itemgetter
n,q=map(int,input().split())
a=[]
s=[0]


for i in range(n-1):
    a.append([int(j) for j in input().split()])
    s.append(0)

a.sort(key=itemgetter(0))

for i in range(0,q):
    P,X=map(int,input().split())
    s[P-1]=s[P-1]+X


for j in range(0,n-1):
    s[a[j][1]-1]=s[a[j][1]-1]+s[a[j][0]-1]


print(' '.join(map(str,s)))
