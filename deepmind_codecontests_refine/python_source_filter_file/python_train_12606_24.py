from operator import itemgetter
n,m=list(map(int,input().split()))
l=[0]*n
counter=0
d=0

for i in range(n):
    l[i]=list(map(int,input().split()))

for i in range(n):
    l[i][1]=l[i][0]-l[i][1]
l.sort(key=itemgetter(1),reverse=True)
for i in range(n):
    counter+=l[i][0]
while counter>=m:
    if d==n:
        print(-1)
        exit()
    counter-=l[d][1]
    d+=1
print(d)