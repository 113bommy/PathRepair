
#k=int(input())
#n,m=map(int,input().split())

#a=list(map(int,input().split()))

#b=list(map(int,input().split()))

x,y,l,r=map(int,input().split())

i=0
a=list()

a.append(l-1)
a.append(r+1)

for i in range(100):
    for j in range(100):
        a.append(x**i+y**j)

a.sort()


m=1

for i in range(len(a)-1):
    if a[i]<=r:
        m=max(m,min(r,a[i+1]-1)-max(a[i]+1,l)+1)


print(m)

'''

a=list(map(int,input().split()))

s=sum(a)

m=int(input())
ss=10**10;

for i in range(m):
    l,r=map(int,input().split())

    if r<s: 
        continue

    ss=min(ss,max(s,l))

if ss==10**10:
    print(-1)
else:
    print(ss)

'''